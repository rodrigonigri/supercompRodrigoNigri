import subprocess
import time
import os

def roda_com_entrada(executavel, input):
    with open(input) as f:
        start = time.perf_counter()
        proc = subprocess.run([executavel], input=f.read(), text=True, capture_output=True)
        end = time.perf_counter()

    return proc.stdout, end-start

