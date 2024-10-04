#!/usr/bin/python3

from google.protobuf.internal.encoder import _VarintEncoder as v
def e(n):
 b=bytearray()
 v()(b.extend,n&(2**32-1),0)
 return b

for i in 12345, 0, 1, 127, 25565, 2097151, 2147483647, -1, -2147483648, 1113983:
  print(e(i).hex())
