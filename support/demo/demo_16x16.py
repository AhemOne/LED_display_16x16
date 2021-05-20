import demo_bitmaps as bitmap

def makeline(lval, rval) :
  lines = []
  for row in range(0,8) :
    lhs = bitmap.numbers[int(lval)][row]
    rhs = bitmap.numbers[int(rval)][row]
    lines.append(lhs * 256 + rhs)
  return lines

def makepanel(hour, minute) :
  lines = makeline(hour/10,hour%10) + makeline(minute/10,minute%10)
  return lines
