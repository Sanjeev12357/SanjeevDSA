class LoopExitException(Exception):
    pass

class LoopSkipException(Exception):
    pass

def extract_block(commands, start):
    
    block = []
    depth = 0
    i = start + 1
    while i < len(commands):
        cmd = commands[i]
        if cmd.startswith('for'):
            depth += 1
        elif cmd == 'done':
            if depth == 0:
                return block, i
            else:
                depth -= 1
        block.append(cmd)
        i += 1
    return block, i

def execute_commands(commands, loop_context, output):
    
    i = 0
    while i < len(commands):
        cmd = commands[i]
        if cmd.startswith('for'):
            parts = cmd.split()
            n = int(parts[1]) if len(parts) < 3 else int(parts[1]) + 1
            # Ensure the next command is 'do'
            if i + 1 >= len(commands) or commands[i + 1] != 'do':
                pass
            block, end = extract_block(commands, i + 1)
            # Execute the block of code for N n
            for count in range(1, n):
                loop_context.append(count)
                try:
                    execute_commands(block, loop_context, output)
                except LoopExitException:
                    loop_context.pop()
                    break
                except LoopSkipException:
                    loop_context.pop()
                    continue
                loop_context.pop()
            i = end + 1
        elif cmd.startswith('print'):
            cur = cmd.split('"')[1] if '"' in cmd else ''
            if cur:
                output.append(cur)
            i += 1
        elif cmd.startswith('break'):
            parts = cmd.split()
            if len(parts) > 1 and loop_context and loop_context[-1] == int(parts[1]):
                raise LoopExitException()
            i += 1
        elif cmd.startswith('continue'):
            parts = cmd.split()
            if len(parts) > 1 and loop_context and loop_context[-1] == int(parts[1]):
                raise LoopSkipException()
            i += 1
        else:
            i += 1



N = int(input())
commands = [input().strip() for _ in range(N)]
output = []
loop_context = []
execute_commands(commands, loop_context, output)
for line in output:
    print(line)