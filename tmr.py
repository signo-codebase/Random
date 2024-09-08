import math as m
import argparse

def TMR(lm, lv, t):
	R2su3 = 3 * m.exp(-2*lm*t) - 2 * m.exp(-3*lm*t)
	print(R2su3 * m.exp(-1*lv*t))

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="Process some integers.")
    parser.add_argument('arg1', type=float, help='First argument')
    parser.add_argument('arg2', type=float, help='Second argument')
    parser.add_argument('arg3', type=float, help='Third argument')

    args = parser.parse_args()
    TMR(args.arg1, args.arg2, args.arg3)
