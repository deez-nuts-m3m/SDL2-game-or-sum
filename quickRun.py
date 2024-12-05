import subprocess

def run_command(command):
    try:
        result = subprocess.run(
            command,
            shell=isinstance(command, str),
            capture_output=True,
            text=True,
            check=True
        )
        return result.returncode, result.stdout, result.stderr
    except subprocess.CalledProcessError as e:
        return e.returncode, e.stdout, e.stderr

run_command("mingw32-Make -f MakeFile")
print("Building done running exe")
subprocess.Popen(["Main.exe"], shell=True)