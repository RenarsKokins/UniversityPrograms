#Renārs Kokins, rk20055
#A8. Dots naturāls skaitlis n. Izdrukāt tos skaitļa n reizinātājus, kuri ir kāda naturāla skaitļa kvadrāti.
#Programma izveidota: 2020/09/27


ok = 1  # While cikla mainīgais, kuru izmainīs, ja vēlēsies beigt programmu
n = 0   # Mainīgais, kurā ievadīs naturālu skaitli

while ok==1:                                        # While cikls, kamēr lietotājs vairs nevēlas palaist programmu
    n = int(input("Ievadiet naturālu skaitli: "))   # Lietotājs ievada skaitli un tas pārveidojas par int veidu
    a = 1                                           # Mainīgais, kurā glabāsies n skaitļa reizinātājs

    if n > 0:                           # Pārbauda, vai skiatlis ir pozitīvs
        while a*a <= n:                 # Sāk while ciklu ar 1^2 un turpina, līdz šis kvadrāts nepārsniedz ievadīto naturālo skaitli
            kvadrats = a*a              # Aprēķina naturāla skaitļa kvadrātu
            if n % kvadrats == 0:       # Pārbauda, vai kvadrāts ir skaitļa n reizinātājs
                print(kvadrats)         # Izvada n skaitļa reizinātāju
            a += 1

    else:
        print("Kļūda. Ievadiet pozitīvu, naturālu skaitli!")
    ok = int(input("Vai vēlaties turpināt (1) vai beigt (0)?\n"))   # Paprasa lietotājam, vai viņš vēlas palaist programmu atkārtoti



# Ievads              Programmas vēlamā reakcija                              Rezultāts Python 3
# 16                  1, 4, 16                                                +

# 100                 1, 4, 25, 100                                           +

# 4096                1, 4, 16, 64, 256, 1024, 4096                           +

# 0                   Kļūda. Nullei nav reizinātāju                           Izdod paziņojumu "Kļūda. Ievadiet pozitīvu, naturālu skaitli!"

# -3                  Kļūda. Nav kvadrātu reizinātāju negatīvam skaitlim      Izdod paziņojumu "Kļūda. Ievadiet pozitīvu, naturālu skaitli!"