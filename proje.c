/*Blackjack oyunu

oyunda kasa ve kullanici olmak uzere iki oyuncu vardir kullanici isim ve sifre girerek oyuna giris yapar,oyuna bahsini koyar, kasanin cektigi ilk karta gore kart cekip cekmemeye karar verir.
kartlar toplami 21 den buyukse oyun kaybedilir.iki tarafinda kartlar toplami 21 den kucukse kartlar toplami en buyuk olan oyunu kazanir yada oyun berabere biter oyun sonunda bakiyeler dosayda guncellenir.



Burak Genc
Diar Begolli
Arda Kazan
Burak Faydali
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct kullanici{
    char kullaniciAdi[20];//structa tutuluan kullanici adi sifre ve bakiyeler
    int kullaniciSifre;
    int kullaniciBakiye;
}	kullanici[10];//10 kullanci oldugu icin [10]


int main()
{
	FILE *fkullanicilar;
    char ad[20];//elle girilecek kullanici adi
    int sifre;//elle girilecek sifre
    int i,n;//dongu icin i , kullanici bulundugunda  kacinci oldugunu hafizada tutmak için n;
    int oyuncubakiye=-1;//kullanici adi veya sifre yanlis girilirse bakiye -1 doner

    fkullanicilar = fopen("kullanicilar.txt","r");//dosya okunuyor
     printf("BLACKJACK OYUNUNA HOSGELDINIZ!\n");
    printf("kullanici adi giriniz: ");//kullanici adi isteniyor
    gets(ad);
    printf("sifre giriniz giriniz: ");//sifre isteniyor
    scanf("%d",&sifre);


    for(i=0;!feof(fkullanicilar);i++){//girilen kullanici adi ve sifre kontrol ediliyor
        fscanf(fkullanicilar,"%s %d %d",kullanici[i].kullaniciAdi,&kullanici[i].kullaniciSifre,&kullanici[i].kullaniciBakiye);

        if((strcmp(kullanici[i].kullaniciAdi,ad)== 0)&&(sifre==kullanici[i].kullaniciSifre )){
                oyuncubakiye=kullanici[i].kullaniciBakiye;//eger bulunduysa o kullanicinin bakiyesi bir degiskene ataniyor
                n=i;//kacinci kullanici oldugunu akilda tutar guncelleme yaparken lazim olacak bide hosgeldin demek icin :)
                }

    }
    if(oyuncubakiye==-1){//bakiye atanmadiysa yani k-kullanici adi sifre yanlissa
        printf("kullanici adi veya sifre yanlisdir daha tekar deneyin. \n");
   }


    else{

    int kasabakiye;//kasanin bakiyesi
    kasabakiye=1000000;
    label://goto icin
    printf("Hosgeldin %s Bakiyende %d tl bulunmaktadir.\n",kullanici[n].kullaniciAdi,oyuncubakiye);


    int oyunayatacakpara=0;

    printf("\nLutfen bu el kac tl ortaya koymak istediginizi girin : ");//oyuncunun oynamak istedigi miktar soruluyor
    scanf("%d",&oyunayatacakpara);

    if(oyunayatacakpara>oyuncubakiye){//oyuncu kendi parasinda cok para girerse

        while(oyunayatacakpara>oyuncubakiye){

            printf("\nYatirmak istediginiz para hesabinizda bulunmamaktadir lutfen bakiyeniz kadar para yatirin:");
            scanf("%d",&oyunayatacakpara);

        }
    }

   oyuncubakiye=oyuncubakiye-oyunayatacakpara;//basiler hesaplardan dusuluyor
   kasabakiye=kasabakiye-oyunayatacakpara;



    int kartlar[4][10]={{1,2,3,4,5,6,7,8,9,10},{1,2,3,4,5,6,7,8,9,10},{1,2,3,4,5,6,7,8,9,10},{1,2,3,4,5,6,7,8,9,10}};//oyunda 1den 10 a kadar 4 er tane sayilar vardir

    int kasatoplamkart=0;

    int kasakart1=0,kasakart2=0,ekstrakasakart=0;
    srand(time(NULL));//dizi icinden random kartlar seciliyor
    int x=rand()%4;
    int y=rand()%10;


    while(kasakart1 == 0){
        x=rand()%4;
        y=rand()%10;
        kasakart1=kartlar[x][y];
    }
    kasatoplamkart+=kasakart1;//cekilen kart toplaniyor kasa icin

    kartlar[x][y]=0;


    //2.kart
    x=rand()%4;
    y=rand()%10;
   kasakart2=kartlar[x][y];
   while(kasakart2 == 0){
        x=rand()%4;
        y=rand()%10;
        kasakart2=kartlar[x][y];
   }
   kasatoplamkart+=kasakart2;//cekilen kart toplaniyor kasa icin

   kartlar[x][y]=0;
   //
//asagi kisimda oyuncu kartlar seciliyor
   int oyuncutoplamkart=0;

   int oyuncukart1=0,oyuncukart2=0,ekstraoyuncukart=0;
    srand(time(NULL));
   x=rand()%4;
   y=rand()%10;

    while(oyuncukart1 == 0){
        x=rand()%4;
        y=rand()%10;
        oyuncukart1=kartlar[x][y];
    }

    oyuncutoplamkart+=oyuncukart1;//cekilen ilk kart toplaniyor oyuncu icin
    kartlar[x][y]=0;

    x=rand()%4;
   y=rand()%10;

    while(oyuncukart2 == 0){
        x=rand()%4;
        y=rand()%10;
        oyuncukart2=kartlar[x][y];
    }

    oyuncutoplamkart+=oyuncukart2;//cekilen ilk kart toplaniyor oyuncu icin

    kartlar[x][y]=0;

    printf("\nBirinci kartiniz[%d],ikici kartiniz[%d],kartlariniz toplami:[%d]\n",oyuncukart1,oyuncukart2,oyuncutoplamkart);

    char secim;

    printf("\nKasanin birinci karti[%d]\n",kasakart1 );
 //tmm


    do{
        printf("\nTekrar kart cekmek isterseniz e'ye yoksa h'ye basin : ");
        scanf(" %c",&secim);
        if(secim=='h'){
            goto h;
        }

        if(secim=='e'){
            ekstraoyuncukart=0;
        }

        while(ekstraoyuncukart==0){
            ekstraoyuncukart=rand()%10;
            ,

        }
        kartlar[x][y]=0;
        printf("\nYeni cektiginiz kart:%d\n",ekstraoyuncukart);
        oyuncutoplamkart+=ekstraoyuncukart;
        printf("\nToplam kartiniz :%d\n",oyuncutoplamkart);


    }while(secim=='e' && oyuncutoplamkart<21);
	h:

    printf("\nKasanin birinci karti [%d],ikinci karti [%d],toplami [%d]\n",kasakart1,kasakart2,kasatoplamkart);

    if(oyuncutoplamkart>21){
        printf("\nIflas ettin toplam kartin [%d]",oyuncutoplamkart);
        kasabakiye+=(oyunayatacakpara*2);
        oyunayatacakpara=0;
    }

	//oyunda gorulebilcek ihtimaller icin gosterilecek sonuclar
    else if(kasatoplamkart<16){//kasa 16 dan buyuk olana kadar kendine kart ceker
            while(kasatoplamkart<16){
                x=rand()%4;
                y=rand()%10;

                while(ekstrakasakart == 0){
                    x=rand()%4;
                    y=rand()%10;
                    ekstrakasakart=kartlar[x][y];
                }
                kartlar[x][y]=0;
                kasatoplamkart+=ekstrakasakart;
                printf("\nkasanin cektigi kart %d kasa toplami %d\n",ekstrakasakart,kasatoplamkart);
                ekstrakasakart=0;
            }
            if(kasatoplamkart>21){
                printf("\nKasa iflas etti OYUNCU KAZANDI\n");
                oyuncubakiye+=(oyunayatacakpara*2);
                oyunayatacakpara=0;
            }
            else if(kasatoplamkart>oyuncutoplamkart){
                printf("\nKASA KAZANDI kasanin kart toplami [%d]\n",kasatoplamkart);
                kasabakiye+=(oyunayatacakpara*2);
                oyunayatacakpara=0;
            }
            else if(oyuncutoplamkart>kasatoplamkart){
                printf("\nSIZ KAZANDINIZ kasanin kart toplami %d\n",kasatoplamkart);
                oyuncubakiye+=(oyunayatacakpara*2);
                oyunayatacakpara=0;
            }
            else if(oyuncutoplamkart==kasatoplamkart){
                printf("\nBerabere bitti\n");
                oyuncubakiye+=oyunayatacakpara;
                kasabakiye+=oyunayatacakpara;
                oyunayatacakpara=0;
            }
    }
    else if(kasatoplamkart>16){
        if(oyuncutoplamkart>kasatoplamkart){
            printf("\nKAZANDINIZ TEBRIKLER\n");
            oyuncubakiye+=(oyunayatacakpara*2);
            oyunayatacakpara=0;
        }
        if(kasatoplamkart>oyuncutoplamkart){
            printf("\nKASA KAZANDI\n");
            kasabakiye+=(oyunayatacakpara*2);
            oyunayatacakpara=0;
        }
        if(kasatoplamkart == oyuncutoplamkart){
            printf("\nBerabere bitti\n");
            kasabakiye+=oyunayatacakpara;
            oyuncubakiye+=oyunayatacakpara;
            oyunayatacakpara=0;
        }
    }

    printf("\n\nSizin bakiyeniz:%d ,kasanin bakiyesi:%d\n\n ",oyuncubakiye,kasabakiye);
    char baslangic;
    printf("\nDevam etmek istiyorsaniz d ye basin cikmak istiyorsaniz baska bir tusa basin");
    scanf("%c",&baslangic);
    if(baslangic=='d'){//kullanici devam etmek istiyorsa d ye basar
        goto label;
    }
    else{
    	kullanici[n].kullaniciBakiye=oyuncubakiye;//oyundan cikarken kullancinin bakiyesini gunceller
    	fkullanicilar = fopen("kullanicilar.txt","w");
    	for(i=0;i<11;i++){
        fprintf(fkullanicilar,"%s %d %d\n",kullanici[i].kullaniciAdi,kullanici[i].kullaniciSifre,kullanici[i].kullaniciBakiye);

	}
}

}
    return 0;
}

