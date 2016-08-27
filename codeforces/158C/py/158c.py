import sys

n = int(input())

pwd = []
for i in range(n):
    cmd = input()
    if cmd == "pwd":
        print("/", end="")
        for j in range(len(pwd)):
            print(pwd[j], end="")
            print("/", end="")
        print()
    else:
        # cd command
        cmd = cmd[3:len(cmd)]
        if cmd == "..":
            pwd.pop()
        elif cmd[0] is '/':
            cmd = cmd[1:len(cmd)]
            cmds = list(cmd.split('/'))
            pwd = []
            for j in range(len(cmds)):
                if cmds[j] == "..":
                    pwd.pop()
                else:
                    pwd.append(cmds[j])
        else:
            cmds = list(cmd.split('/'))
            for j in range(len(cmds)):
                if cmds[j] == "..":
                    pwd.pop()
                else:
                    pwd.append(cmds[j])

