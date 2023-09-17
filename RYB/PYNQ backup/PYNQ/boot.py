#! /usr/bin/env python3


from time import sleep
import subprocess
import pynq

base = pynq.Overlay("/boot/io0.2.0.bit")


subprocess.run(["/boot/startup.sh"])
