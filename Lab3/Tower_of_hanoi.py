step = 0
def TOH(n, src, dst, tmp):
    global step
    if n == 1:
        print(f"Step {step}: Move disc {n} from {src} to {dst}.")
        step += 1
    else:
        TOH(n-1, src, tmp, dst)
        print(f"Step {step}: Move disc {n} from {src} to {dst}.")
        step += 1
        TOH(n-1, tmp, dst, src)

TOH(20, "A" , "C", "B")
