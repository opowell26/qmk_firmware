"""Used by the make system to generate keycodes.h from keycodes_{version}.json
"""
from milc import cli

from qmk.constants import GPL2_HEADER_C_LIKE, GENERATED_HEADER_C_LIKE
from qmk.commands import dump_lines
from qmk.path import normpath
from qmk.keycodes import load_spec


def _generate_ranges(lines, keycodes):
    lines.append('')
    lines.append('enum qk_keycode_ranges {')
    lines.append('// Ranges')
    for key, value in keycodes["ranges"].items():
        lo, mask = map(lambda x: int(x, 16), key.split("/"))
        hi = lo + mask
        define = value.get("define")
        lines.append(f'    {define.ljust(30)} = 0x{lo:04X},')
        lines.append(f'    {(define + "_MAX").ljust(30)} = 0x{hi:04X},')
    lines.append('};')


def _generate_defines(lines, keycodes):
    lines.append('')
    lines.append('enum qk_keycode_defines {')
    lines.append('// Keycodes')
    for key, value in keycodes["keycodes"].items():
        lines.append(f'    {value.get("key")} = {key},')

    lines.append('')
    lines.append('// Alias')
    for key, value in keycodes["keycodes"].items():
        temp = value.get("key")
        for alias in value.get("aliases", []):
            lines.append(f'    {alias.ljust(10)} = {temp},')

    lines.append('};')


def _generate_helpers(lines, keycodes):
    lines.append('')
    lines.append('// Range Helpers')
    for value in keycodes["ranges"].values():
        define = value.get("define")
        lines.append(f'#define IS_{define}(code) ((code) >= {define} && (code) <= {define + "_MAX"})')

    # extract min/max
    temp = {}
    for key, value in keycodes["keycodes"].items():
        group = value.get('group', None)
        if not group:
            continue
        if group not in temp:
            temp[group] = [0xFFFF, 0]
        key = int(key, 16)
        if key < temp[group][0]:
            temp[group][0] = key
        if key > temp[group][1]:
            temp[group][1] = key

    lines.append('')
    lines.append('// Group Helpers')
    for group, codes in temp.items():
        lo = keycodes["keycodes"][f'0x{codes[0]:04X}']['key']
        hi = keycodes["keycodes"][f'0x{codes[1]:04X}']['key']
        lines.append(f'#define IS_{ group.upper() }_KEYCODE(code) ((code) >= {lo} && (code) <= {hi})')


@cli.argument('-v', '--version', arg_only=True, required=True, help='Version of keycodes to generate.')
@cli.argument('-o', '--output', arg_only=True, type=normpath, help='File to write to')
@cli.argument('-q', '--quiet', arg_only=True, action='store_true', help="Quiet mode, only output error messages")
@cli.subcommand('Used by the make system to generate keycodes.h from keycodes_{version}.json', hidden=True)
def generate_keycodes(cli):
    """Generates the keycodes.h file.
    """

    # Build the keycodes.h file.
    keycodes_h_lines = [GPL2_HEADER_C_LIKE, GENERATED_HEADER_C_LIKE, '#pragma once', '// clang-format off']

    keycodes = load_spec(cli.args.version)

    _generate_ranges(keycodes_h_lines, keycodes)
    _generate_defines(keycodes_h_lines, keycodes)
    _generate_helpers(keycodes_h_lines, keycodes)

    # Show the results
    dump_lines(cli.args.output, keycodes_h_lines, cli.args.quiet)
