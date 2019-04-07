import math


if __name__ == '__main__':

    test = int(input())

    for t in range(1,test+1):
        z = input().split(' ')
        primes = []
        list = []
        list = input().split(' ')

        n = len(list)

        for i in range(0,n):
            list[i]= int(list[i])

        a = 0
        b = 0

        for i in range(0,n-1):
            if list[i] != list[i+1]:
                b = math.gcd(list[i],list[i+1])
                a = list[i]//b
                idx = i
                while idx > 0:
                    idx -= 1
                    a = list[idx]//a
                break

        numbers = [a]
        for i in list:
                numbers.append(i//numbers[-1])

        for i in numbers:
            if not primes.count(i):
                primes.append(i)

        primes = sorted(primes)
                
        sol = ""
        for i in numbers:
            sol += chr(ord('A')+primes.index(i))

        print("Case #"+str(t)+":",sol)
