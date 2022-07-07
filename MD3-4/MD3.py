#Renārs Kokins, rk20055
#MD3. Lietotājs ievada trīs veselus skaitļus. Izdrukāt visu ievadīto nepāra skaitļu vidējo vērtību (piemēram, ja lietotājs ievadījis skaitļus 3, 10 un 7, tad jāizvada (3+7)/2 jeb 5).
#Programma izveidota: 2020/09/17

ok = 1                                                                      # While cikla mainīgais, kuru izmainīs, ja vēlēsies beigt programmu

while ok==1:                                                                # While cikls, kuru lietotājs varēs izbeigt
    nepara_sk = []                                                          # Izveido tukšu list, kurā glabāsies nepāra skaitļi
    summa = 0                                                               # Tajā tiks glabāta nepāra skaitļu summa
    videjais = 0                                                            # Tajā tiks glabāts vidējais, kuru arī izvadīs ārā

    skaitli = input("Ievadiet veselus skaitļus(atdalītus ar atstarpi): ")   # Lietotājs ievada skaitļus un tos saglabā "skaitli" mainīgajā
    skaitli = skaitli.split()                                               # Sadala string atstarpes un iegūst atdalītus skaitļus
    skaitli = map(int, skaitli)                                             # Pārveido str list par int list

    for skaitlis in skaitli:                    # Iziet cauri katram skaitli, lai varētu noteikt, vai tie ir pāra vai nepāra
        if skaitlis % 2 != 0:                   # Ja skaitlis ir nepāra, to pievieno "nepara_sk" list
            nepara_sk.append(skaitlis)

    for skaitlis in nepara_sk:                  # Iziet cauri katram skaitlim "nepara_sk" list
        summa = summa + skaitlis                # Pievieno skaitļus summai

    if (summa != 0) & (len(nepara_sk)>0):       # Pārbauda, vai summa nav 0
        videjais = int(summa/len(nepara_sk))    # Aprēķina vidējo
        print(videjais)                         # Izvada vidējo
    else:
        print("Summa ir 0, tāpēc arī vidējais ir 0")

    ok = int(input("Vai vēlaties turpināt (1) vai beigt (0)?\n"))   # Paprasa lietotājam, vai viņš vēlas palaist programmu atkārtoti



# Ievads              Programmas vēlamā reakcija                              Rezultāts Python 3
# 3 10 7              5                                                       +

# -9 12 156 -100      -9                                                      +

# 0 0 0 0             0                                                       Izdod paziņojumu "Summa ir 0, tāpēc arī vidējais ir 0"

# 10 10 10 -9 13      2                                                       +

# -3                  -3                                                      +





