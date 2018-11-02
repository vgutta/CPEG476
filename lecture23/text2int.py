m = "Friday"

print m

hexstr = m.encode('hex')

print hexstr

integer_m = int(hexstr, 16)

print integer_m

back2hex = format(integer_m, 'x')

print back2hex

evenpad = ('0' * (len(back2hex) % 2)) + back2hex

plaintext = evenpad.decode('hex')

print plaintext
