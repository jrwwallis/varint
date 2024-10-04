#!/bin/bash

if make varint_test; then
  ./varint_test | diff -u output.ok.txt -
fi
