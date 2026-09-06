#!/bin/bash
# Simple test script for the 'harness' program

# printf builds the input: one word per line, just like a user typing and pressing Enter.
# "hello\n" simulates typing "hello" and hitting Enter.
# "exit\n" simulates typing "exit" and hitting Enter.
# The pipe (|) sends that text into harness's standard input, as if it were typed live.
printf "hello\nexit\n" | ./harness
