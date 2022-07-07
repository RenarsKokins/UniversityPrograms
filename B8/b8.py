#Renārs Kokins, rk20055

#B8. Doti trīs naturāli skaitļi. Noteikt, vai starp dotajiem skaitļiem ir tāds, kura ciparu summa ir vienāda ar pārējo divu skaitļu starpību. 
#Ja ir, izdrukāt šo skaitli. Skaitļu dalīšana ciparos jāveic skaitliski. Risinājumā izmantot funkciju, kas aprēķina skaitļa ciparu summu.

#Programma izveidota: 2020/10/22

def Sum(n):
    out = 0
    while(n>=10):
        out += n%10
        n //= 10
    out += n
    return out

ok = 1  # While cikla mainīgais, kuru izmainīs, ja vēlēsies beigt programmu

while ok==1:                                                                            # While cikls, kamēr lietotājs vairs nevēlas palaist programmu
    a, b, c = input("Ievadiet naturālos skaitļus(pirmais, otrais, trešais): ").split()  # Lietotājs ievada skaitli un tas pārveidojas par int veidu)
    a, b, c = int(a), int(b), int(c)                                                    # Pārveido ievadītos mainīgos par int tipu
    cik = 0

    if ((a>=0) & (b>=0) & (c>=0)):
        if((Sum(a)==b-c) | (Sum(a)==c-b)):  # Pārbauda, vai a mainīgā skaitļu summa nav veināda ar pārējo skaitļu starpību. Ja ir, izdrukā šo skaitli.
            print(a) 
            cik += 1
        if((Sum(b)==a-c) | (Sum(b)==c-a)):  # Pārbauda, vai b mainīgā skaitļu summa nav veināda ar pārējo skaitļu starpību. Ja ir, izdrukā šo skaitli.
            print(b) 
            cik += 1
        if((Sum(c)==a-b) | (Sum(c)==b-a)):  # Pārbauda, vai c mainīgā skaitļu summa nav veināda ar pārējo skaitļu starpību. Ja ir, izdrukā šo skaitli.
            print(c) 
            cik += 1

        if cik==0:
            print("Nav tāda skaitļa, kura ciparu summa ir vienāda ar pārējo divu skaitļu starpību")

    else:
        print("Kļūda. Ievadiet pozitīvu, naturālu skaitli!")

    ok = int(input("Vai vēlaties turpināt (1) vai beigt (0)?\n"))   # Paprasa lietotājam, vai viņš vēlas palaist programmu atkārtoti



# Ievads       Programmas vēlamā reakcija                                                                           Rezultāts Python 3
# 8 0 8        8 0 8                                                                                                +

# 1 2 3        1 2                                                                                                  +

# 16 14 7      16                                                                                                   +

# 31 4 6       Paziņojums. Netika ievadīts skaitlis, kura ciparu summa ir vienāda ar pārējo divu skaitļu starpību   Izdod paziņojumu "Nav tāda skaitļa, kura ciparu summa ir vienāda ar pārējo divu skaitļu starpību"

# -3 4 -5      Kļūda. Netika ievadīti naturāli skaitļi                                                              Izdod paziņojumu "Kļūda. Ievadiet pozitīvu, naturālu skaitli!"