#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int TopPuan=0;
int kulKupon[6],blgKupon[6],frekans[54]={0},frekans1[54],frekans2[54]={0},dizi0[54],dizi1[54],sayac[4];
char sor;
int AnaMenu();
void IstMenu();
int Loto();
void Tekrar();
int soru(int);

int main()
{
    int besleme;
    printf("Besleme icin numara giriniz: ");
    scanf("%d",&besleme);
    srand(besleme);                                             //Random seed i�in kullan�c�dan sayi istenmesi//
    AnaMenu();
    return 0;
}

int AnaMenu(){
    int Ter1;
    printf("\n\tANA MENU");
    printf("\n1.Super Loto (6/54) Oynama\n2.Istatistikleri Goruntuleme\n3.Cikis");
    printf("\n(Toplam odulunuz:%d puan)",TopPuan);
    do{
        printf("Seciminiz: ");                                  //Kullan�c�dan 1-3 aras� deger istenmesi//
        scanf("%d",&Ter1);
        if (Ter1<1 || Ter1>3){
            printf("\nLutfen 1-3 arasi secim yapin!");
        }
    }while (1>Ter1 || Ter1>3);
    if (Ter1==1){
        Loto();
        Tekrar();
    }
    if (Ter1==2){
        IstMenu();
    }
    if (Ter1==3){                                               //Kullan�c�ya anamen�de toplam puan� g�sterilmesi//
        printf("\nToplam puaniniz:%d",TopPuan);
        printf("\nProgramdan cikmak istediginizden emin misiniz?(Evet:E/e-Hayir:H/h): ");
        soru(1);
    }
}
int Loto(){
    int i,j,u,m,tut,tur,TutSayi,kulKupon1[10];
    unsigned int blgRand;
    for (i=0;i<6;i++){
        j=1;
        do{
            printf("Kupon icin %d.sayiyi gir: ",i+1);
            scanf("%d",&kulKupon1[i]);
            if (1>kulKupon1[i] || kulKupon1[i]>54){
                printf("\nLutfen 1-54 arasi sayilari kullanin!\n");
            }
            u=0;                                                //Kullan�c�dan kupona uygun olacak �ekilde say�lar al�nmas�//
            for (m=0;m<i;m++){                                  //Do while �n i�icnde local dizi olu�turulmas�//
                if (kulKupon1[i]==kulKupon1[m]){
                    u+=1;
                    printf("\nDaha once kullandigin sayi var!\n");
                    j=0;
                }
            }
            if (u==0){
                j=1;
            }
        }while (1>kulKupon1[i] || kulKupon1[i]>54 || j==0);
    }
    for (i=0;i<6;i++){
        kulKupon[i]=kulKupon1[i];                               //Local dizi,global de�i�ken olarak atan�yor//                               //
    }
    for (i=0;i<6;i++){
        blgRand=1+rand()%54;
        blgKupon[i]=blgRand;
        for (j=0;j<i;j++){                                      //Bilgisayar�n random kupon olu�turmas�//
            while (blgKupon[i]==blgKupon[j]){
                blgRand=1+rand()%54;
                blgKupon[i]=blgRand;
            }
        }
    }
   for (tur=0;tur<5;tur++){
        for (i=0;i<5;i++){
            if (kulKupon[i]>kulKupon[i+1]){
                tut=kulKupon[i];                                //Kullan�c� kuponunun baloncuk s�ralanma ile s�ralanmas�//
                kulKupon[i]=kulKupon[i+1];
                kulKupon[i+1]=tut;
            }
        }
   }
   for (tur=0;tur<5;tur++){
        for (i=0;i<5;i++){
            if (blgKupon[i]>blgKupon[i+1]){
                tut=blgKupon[i];                                //Bilgisayar kuponunun baloncuk s�ralama ile s�ralanmas�//
                blgKupon[i]=blgKupon[i+1];
                blgKupon[i+1]=tut;
            }
        }
    }
    printf("\nKendi kuponunuz: \n");
    for (i=0;i<6;i++){
        printf("%d\t",kulKupon[i]);
    }                                                           //Her iki kupon ekrana yazd�r�l�yor//
    printf("\nBilgisayarin kuponu: \n");
    for (i=0;i<6;i++){
        printf("%d\t",blgKupon[i]);
    }
    TutSayi=0;
    for (i=0;i<6;i++){
        for (j=0;j<6;j++){
            if (kulKupon[i]==blgKupon[j]){
                TutSayi+=1;                                     //�ki kuponda e�lesen say�lar�n g�sterilmesi//
                if (TutSayi>0){
                    printf("\nTutturdugunuz %d.sayi:%d ",TutSayi,kulKupon[i]);
                }
            }
        }
    }
    switch(TutSayi){
        case 0:
            printf("\nPuan kazanamadiniz");
            break;
        case 1:
            printf("\nPuan kazanamadiniz");                     //Toplam puan� puanlama sistemiyle olu�turan switch yap�s�//
            break;
        case 2:
            printf("\nPuan kazanamadiniz");
            break;
        case 3:
            TopPuan+=1;                                         //�statistik k�sm�nda kolayl�k olsun diye dizi atan�yor//
            sayac[0]+=1;                                        //Sayac adl� degiskende puanlar tutuluyor//
            printf("\n1 puan kazandiniz");
            break;
        case 4:
            TopPuan+=3;
            sayac[1]+=1;
            printf("\n3 puan kazandiniz");
            break;
        case 5:
            TopPuan+=10;
            sayac[2]+=1;
            printf("\n10 puan kazandiniz");
            break;
        case 6:
            TopPuan+=50;
            sayac[3]+=1;
            printf("\n50 puan kazandiniz");
            break;
        default:
            printf("\nHata kazanamadiniz");
            break;
    }
    printf("\nToplam Puaniniz:%d",TopPuan);                     //Toplam puan ekrana burdada yazd�r�l�yor//
    for(i=0;i<6;i++){
        ++frekans[blgKupon[i]];
    }
    for (i=0;i<6;i++){
        ++frekans2[kulKupon[i]];                                //Frekans adl� iki global dizi istatistikler i�in olu�uyor//
    }                                                           //��kan her de�er dizlerde kendi yerinde saklan�yor//
}
void Tekrar(){                                                  //Buras� yap�lmay�p loto fonksiyonuna ba�lanabilrdi//
    printf("\nTekrar oynamak ister misiniz?(Evet:E/e Hayir:H/h): ");
    soru(2);
}
void IstMenu(){
   int i,j,k=0,Ter2,yild,Tut,say,Tut0;
   printf("\n\n\tISTATISTIK ANA MENUSU");
   printf("\n1.Cekilislerde cikan sayilarin kac kez ciktiklarinin listelenmesi");
   printf("\n2.Cekilislerde en az 1 kez cikan sayilarin kac kez ciktiklarina gore sirali olarak listelenmesi");
   printf("\n3.Oyuncunun hangi odulleri kacar kez kazandiginin listelenmesi");
   printf("\n4.Oyuncunun en cok tercih ettigi 3 sayinin listelenmesi");
   printf("\n5.Ana Menu");
   do{
       printf("\nSeciminiz: ");                                 //Kullan�c�dan 1-5 aras� deger girilmesi//
       scanf("%d",&Ter2);
       if (Ter2<1 || Ter2>5){
            printf("\nLutfen 1-5 arasi rakamlari kullaniniz");
       }
   }while(Ter2<1 || Ter2>5);
   for (i=0;i<54;i++){
       frekans1[i]=frekans[i];                                  //Global frekans dizisi de�i�meden s�ralama yapmak gerekiyor//
       dizi0[i]=i+1;                                            //Frekans ve i�indeki sayilar i�in iki dizi olu�uyor//
   }
   for (i=0;i<54;i++){                                          //Bu dizi1 ve dizi0 numaralar�n yerlerini tutucak//
       dizi1[i]=i+1;
   }
   for (j=0;j<52;j++){
       for (i=1;i<53;i++){
           if (frekans1[i]<frekans1[i+1]){
               Tut=frekans1[i];
               frekans1[i]=frekans1[i+1];                       //Bir �stte atanan frekans1 dizisi dizi0 ile beraber s�ralan�yor//
               frekans1[i+1]=Tut;                               //B�ylece sayilar s�ralansa bile dizi0 dizsi ile numaralar�n,
               Tut0=dizi0[i];                                                 //nerde oldu�u saklan�yor//
               dizi0[i]=dizi0[i+1];
               dizi0[i+1]=Tut0;
            }
        }
   }
   for (j=0;j<52;j++){
       for (i=0;i<53;i++){
           if (frekans2[i]<frekans2[i+1]){
               Tut=frekans2[i];
               frekans2[i]=frekans2[i+1];                       //�stteki yap�lan s�ralama frekans2 i�in de dizi1 ile yap�l�yor//
               frekans2[i+1]=Tut;
               Tut0=dizi1[i];
               dizi1[i]=dizi1[i+1];
               dizi1[i+1]=Tut0;
           }
       }
   }
   switch(Ter2){                                                //Men�de ullan�c�n�n tercih etti�i rakam i�in switch yap�s�//
       case 1:
           printf("\n\n\tCekilislerde Cikan Sayilarin Kacar Kez Ciktigi Liste:\n\n");
           printf("%9s%10s%15s","Sayi","Kac Kez","Cubuk Grafik");
           printf("\n%9s%10s%15s","____","_______","____________");
           for (i=0;i<54;i++){
                printf("\n%7d\t%8d\t",i+1,frekans[i]);
                yild=frekans[i];
                if (yild>0){
                    while (yild>0){                             //1.nolu tercihte y�ld�z yazd�r�rken global dizi de�i�memesi i�in
                        printf("*");                                      //Dizinin elemanlar� yild adli de�i�kene atan�yor//
                        yild-=1;
                    }
                }
                if (i==17 || i==37 || i==53){                   //Konsol uzunlugu 24 oldugundan ara ara ENTER istenmesi//
                    if (i==53){
                        printf("\nListeniyi kapatmak icin ENTERe basiniz!");
                    }
                    else{
                        printf("\nListenin devami icin ENTERe basiniz!\n");
                    }
                    getchar();                                 //Getchar adl� fonksiyon kullan�lmas�//
                    if (k==0){
                        getchar();
                    }
                    if (i!=53){
                    printf("%9s%10s%15s","Sayi","Kac Kez","Cubuk Grafik");
                    printf("\n%9s%10s%15s","____","_______","____________");
                    }
                    k++;
                 }
           }
           k=0;
           IstMenu();
           break;
       case 2:
           printf("\n\n\tCekilislerde En Az Bir Kez Cikan Sayilarin Kac Kez Ciktiklarina Gore\n\t\t\tSirali Olarak Listesi:\n\n");
           printf("%9s%10s%15s","Sayi","Kac Kez","Cubuk Grafik");
           printf("\n%9s%10s%15s","____","_______","____________");
           Tut0=0;
           say=1,k=0;
           for (i=0;i<54;i++){
               if (frekans1[i]!=0){
                   say+=1;
                   printf("\n%7d\t%8d\t",dizi0[i],frekans1[i]);
                   yild=frekans1[i];
                       while (yild>0){                          //Yine y�ld�z yazd�rmak i�in ayn� de�i�ken kullan�ld�//
                           printf("*");
                           yild-=1;
                       }
                   if (say==15 || say==38 || say==53){
                       if (say==53){                            //Konsol uzunlugu 24 oldugundan ara ara ENTER istenmesi//
                           printf("\nListeniyi kapatmak icin ENTERe basiniz!");
                       }
                       else{
                           printf("\nListenin devami icin ENTERe basiniz!\n");
                       }
                       getchar();
                       if (k==0){
                           getchar();
                       }
                       printf("%9s%10s%15s","Sayi","Kac Kez","Cubuk Grafik");
                       printf("\n%9s%10s%15s","____","_______","____________");
                       k++;
                   }
               }
               if (frekans1[i]==0){
                   Tut0+=1;
               }
           }
           if (Tut0==54){                                       //Kullan�c� kupon yapmadan istatistik men�s�ne girerse,
               printf("\n\tHENUZ KUPON YAPMAMISSIZNIZ");                //2.ve4. se�eneklerde "Kupon Yap�lamam��" yazd�r�l�yor//
           }
           k=0;
           say=0;
           IstMenu();
           break;
       case 3:
           printf("\n\n\t%s\n\n","Oyuncunun Hangi Odulleri Kacar Kez Kazandiginin Listesi:");
           printf("\t%s\t%s\t\t%s","Dogru Tahmin Sayisi","Kac Kez","Kazandigi Odul Puani");
           printf("\n\t%s\t%s\t\t%s","___________________","_______","____________________");
           for (i=0;i<4;i++){
               switch (i){                                      //3.tecihte puanlar i�in bir switch yap�s�//
                  case 0:
                      j=1;
                      break;
                  case 1:
                      j=3;
                      break;
                  case 2:
                      j=10;
                      break;
                  case 3:
                      j=50;
                      break;
                  default:
                      break;
               }                                                //Burada 3.tercih i�in sonu�lar yazd�r�l�yor//
               printf("\n%16d%20d%22d",i+3,sayac[i],sayac[i]*j);
           }
           IstMenu();
           break;
       case 4:
           printf("\n\n\tOyuncunun En Cok Tercih Ettigi Uc Sayinin Listesi:\n\n");
           printf("\t%s\t%s","Sayi","Oynanma Sayi");
           printf("\n\t%s\t%s","____","____________");
           Tut0=0;
           for (i=0;i<3;i++){
                if (frekans2[i]!=0){
                    printf("\n\t%d\t%7d",dizi1[i],frekans2[i]);
                }
                else{
                    Tut0+=1;
                }
           }
           if (Tut0==3){                                        //Buradaki "Kupon Yap�lmam�� uyar�s�//
                printf("\n\tHENUZ KUPON YAPMAMISSINIZ\n");
           }
           IstMenu();
           break;
       case 5:
           AnaMenu();                                           //�statistikten ana men�ye d�nme k�sm�//
       default:
            break;
    }
}
int soru(int menu){                                             //Tekrar oynama ve programdan ��k�� sorular�
    do{                                                               //bu fonksiyonda soruluyor //
        if (menu==1 || menu==2){
            scanf("%c",&sor);
        }
        sor=getchar();
        if (sor!='E' && sor!='e' && sor!='H' && sor!='h'){
            printf("E-e-H-h karakterlerini kulanin!Tercihiniz: ");
        }
    }while(sor!='E' && sor!='e' && sor!='H' && sor!='h');
    if (menu==1){
        if (sor=='E' || sor=='e'){
            return;
        }
        else{
            AnaMenu();
        }
     }
     if (menu==2){
        if (sor=='E' || sor=='e'){
            Loto();
            Tekrar();
        }
        else{
            AnaMenu();
        }
     }
}
