#include <stdio.h>
#include <stdlib.h>

//TUNCAY BAYIR
//tuncayorgundar@gmail.com
//bu otomasyon basit islemlere, basit sisteme, basit mantik yapisina sahiptir.

typedef struct urunler
{
    char urun_adi[15];
    int urun_kodu;
    int urun_fiyati;

} urun;

typedef struct veresiyedefteri
{

    char musteri_adi[15];
    char musteri_soyadi[15];
    int musteri_kodu;
    int musteri_borcu;
} defter;

typedef struct genelbilgiler
{
    defter musteri_bilgileri;
    urun urunbilgileri;
} genelbilgi;

void urunlerin_sisteme_kaydi(genelbilgi *kayit);
void urun_yazdirma(genelbilgi *yazdirma);
void urun_bilgisi(genelbilgi *bilgi);
void urun_silme(genelbilgi *silmeadresi,genelbilgi *silmekodu);
void urun_guncelleme(genelbilgi *bellekadres,genelbilgi *oncekikod);

void musteri_kayit(genelbilgi *musterikayit);
void musteri_listeleme(genelbilgi *musterilisteleme);
void musteri_guncelleme(genelbilgi *musteriguncelleme, genelbilgi *guncellemekod);
void musteri_silme(genelbilgi *musterisilme, genelbilgi *silmekod);

void fis_olusturma(genelbilgi *fisolusturma);

void urun_satma(genelbilgi *urunsatma, genelbilgi *satmakodu);
void tahmini_kar_hesabi(genelbilgi *karhesabi);
void urun_iade(genelbilgi *iade,int iadekod,int iadefiyat, char iadeisim[15]);


int main()
{
    int numara,uboyut,urunboyut;
    int boyut,i,uruntus,tus;
    int defterno;
    int sistemkayit;

    genelbilgi *gkod;
    genelbilgi *eskikod;
    genelbilgi *urunlerp;
    genelbilgi *urunlerpg;
    genelbilgi *urungirme;

//DEFTER MENUSU ILE ALAKALI TANIMLAMALAR

    int mboyut,mboyutl;
    int mustus=0;

    genelbilgi *defterbellek;
    genelbilgi *defterbellekg;
    genelbilgi *moncekikod;
    genelbilgi *msilmekod;
    genelbilgi *musekleme;


    int satno,*satboyutp,satboyut;
    genelbilgi *satkod;
    int iadekod,iadefiyat;
    char iadeisim[15];
    genelbilgi *urunler;

    printf("\t\t\tMerhaba, Gundar Markete hos geldiniz.\n\n");
    printf("\t\t    oncelikle sizden birkac sey istemem gerekiyor\2\2\2\n\n");

    printf("lutfen urun sayinizi giriniz:");
    scanf("%d",&boyut);

    urunlerp = (genelbilgi*) calloc(boyut,sizeof(genelbilgi));
    if(urunlerp==NULL)
    {
        printf("yetersiz bellek!\n");
    }
    urunlerpg=urunlerp;
    urungirme=urunlerp;

    printf("musteri sayinizi giriniz:");
    scanf("%d",&mboyut);

    defterbellek=(genelbilgi*)calloc(mboyut,sizeof(genelbilgi));
    if(defterbellek==NULL)
    {
        printf("yetersiz bellek!\n");
    }
    defterbellekg=defterbellek;
    musekleme=defterbellek;

    printf("sisteme 2 tane urun kaydi yapmak ister misiniz?(e->1 | h->0):");
    scanf("%d",&sistemkayit);
    if(sistemkayit==1)
    {
        urunlerin_sisteme_kaydi(urunlerpg);
    }

menu:
    printf("\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\n");
    printf("1-urun islemleri\n");
    printf("2-Veresiye defteri\n");
    printf("3-satis islemleri\n");
    printf("4-Fis olusturma\n");
    printf("5-Ekrani temizleme\n");
    printf("6-programdan cikma\n");
    printf("\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\n");

    printf("Lutfen girmek istediginiz menunun numarasini girin:");
    scanf("%d",&numara);

    switch (numara)
    {
    case 1:

urunmenu:
        printf("\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\n");
        printf("1-Urun ekleme\n");
        printf("2-Urunleri listeleme\n");
        printf("3-Urun guncelleme\n");
        printf("4-Urun silme\n");
        printf("5-satis islemleri menusu\n");
        printf("6-ana menuye donme\n");
        printf("\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\n");

        printf("lutfen girmek istediginiz bolumun numarasini giriniz:");
        scanf("%d",&urunboyut);

        switch (urunboyut)
        {
        case 1:

            uruntus=0;
            while(uruntus==0)
            {

                urun_bilgisi(urungirme++);
                printf("baska urun eklemek istiyor musunuz( e-0 | h-1 ):");
                scanf("%d",&uruntus);
                if(urunler==0)
                {
                    urunler=(genelbilgi*) realloc(urunler,(boyut)*sizeof(genelbilgi));
                }


            }

            printf("\nurunleriniz basariyla eklenmistir\n\n");

            goto urunmenu;

            break;
        case 2:
            printf("listelemek istediginiz urun sayisini giriniz:");
            scanf("%d",&uboyut);

            for(i=0; i<uboyut; i++)
            {
                urun_yazdirma(urunlerpg+i);

            }
            printf("\nurunleriniz basariyla listelenmistir\n");
                goto urunmenu;
            break;

        case 3:


            printf("guncelleyeceginiz urunun kodunu giriniz:");
            scanf("%d",&eskikod);

            urun_guncelleme(urunlerpg,eskikod);

                goto urunmenu;

            break;

        case 4:

            printf("lutfen silmek istediginiz urunun kodunu girin:");
            scanf("%d",&gkod);

            urun_silme(urunlerpg,gkod);

                goto urunmenu;

               break;

        case 5:

               goto satismenu;

            break;
        case 6:

             goto menu;

             break;

        default:
            printf("yanlis tus girdiniz lutfen menude olan tuslari giriniz\n");
            goto urunmenu;

        }
    case 2:

deftermenu:
        printf("\2\2\2\2\2\2\2\2\2\2\2\2\2\2\2\2\2\2\2\2\2\2\2\2\2\n");
        printf("1-musteri kayit\n");
        printf("2-musteri bilgileri\n");
        printf("3-musteri guncelleme\n");
        printf("4-musteri silme\n");
        printf("5-ana menuye donme\n");
        printf("\2\2\2\2\2\2\2\2\2\2\2\2\2\2\2\2\2\2\2\2\2\2\2\2\2\n");

        printf("girmek istediginiz bolumun no'sunu giriniz:");
        scanf("%d",&defterno);

        switch(defterno)
        {
        case 1:

            mustus=0;
            while(mustus==0)
            {
                musteri_kayit(musekleme++);
                printf("baska musteri eklemek istiyor musunuz(e-0 | h-1):");
                scanf("%d",&mustus);
                if(urunler==0)
                {
                    urunler=(genelbilgi*)realloc(urunler,boyut*sizeof(genelbilgi));
                }

            }
            printf("\nmusterileriniz basariyla eklenmistir\n");

                goto deftermenu;

            break;

        case 2:

            printf("listelemek istediginiz musteri sayisini giriniz:");
            scanf("%d",&mboyutl);

            for(i=0; i<mboyutl; i++)
            {
                musteri_listeleme(defterbellekg+i);
            }
            printf("\nmusterileriniz basariyla listelenmistir\n");

                goto deftermenu;

            break;

        case 3:


            printf("guncellemek istediginiz musterinin kodunu giriniz:");
            scanf("%d",&moncekikod);

            musteri_guncelleme(defterbellekg,moncekikod);

                goto deftermenu;

            break;

        case 4:

            printf("silmek istediginiz musterinin kodunu giriniz:");
            scanf("%d",&msilmekod);

            musteri_silme(defterbellekg,msilmekod);

                goto deftermenu;

            break;

        case 5:

                goto menu;

            break;
        default:
            printf("yanlis tus girdiniz lutfen menude olan tuslari giriniz\n");
            goto deftermenu;
        }
            goto menu;

        break;
    case 3:
satismenu:
        printf("\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\n");
        printf("1-urun satma\n");
        printf("2-tahmini kar hesabi\n");
        printf("3-urun iade\n");
        printf("4-urun islemleri menusu\n");
        printf("5-ana menuye donme\n");
        printf("\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\n");

        printf("girmek istediginiz bolumun numarasini girin:");
        scanf("%d",&satno);

        switch (satno)
        {
        case 1:

            printf("satmak istediginiz urunun kodunu giriniz:");
            scanf("%d",&satkod);

            satboyutp=(&satkod);
            satboyut=(*satboyutp);

            for(i=0; i<=satboyut; i++)
            {
                if(satboyut==(urunlerpg+i)->urunbilgileri.urun_kodu)
                {
                    iadekod=(urunlerpg+i)->urunbilgileri.urun_kodu;
                    iadefiyat=(urunlerpg+i)->urunbilgileri.urun_fiyati;
                    strcpy(iadeisim,(urunlerpg+i)->urunbilgileri.urun_adi);
                }

            }

            urun_satma(urunlerpg,satkod);

            goto satismenu;

            break;

        case 2:

            tahmini_kar_hesabi(urunlerpg);

            goto satismenu;

            break;
        case 3:

            urun_iade(urunlerpg,iadekod,iadefiyat,iadeisim);

                goto satismenu;

            break;
        case 4:


                goto urunmenu;

            break;

        case 5:

                goto menu;

            break;
        default:
            printf("lutfen menude olan numaralardan birisini giriniz\n");

            goto satismenu;
        }


    case 4:

        fis_olusturma(urunlerpg);

        printf("ana menuye gitmek icin 0 rakamini tuslayiniz:");
        scanf("%d",&tus);
        if(tus==0)
        {
            goto menu;
        }
        else
        {
            printf("yanlis tuslama yaptiniz");
            goto menu;
        }

    case 5:

            system("cls");

            goto menu;

        break;

    case 6:

            exit(0);

    default:

        printf("yanlis tuslama yaptiniz lutfen menude olan rakamlari giriniz\n");

        goto menu;

        break;


    }

    return 0;
}


void urun_bilgisi(genelbilgi *bilgi)
{
    char ad[25];

    printf("\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\4\n");

    printf("urun adini giriniz:");
    scanf("%s",&(bilgi->urunbilgileri.urun_adi));

    while(bilgi->urunbilgileri.urun_kodu==0)
    {
        printf("urun kodunu giriniz:");
        scanf("%d",&(bilgi->urunbilgileri.urun_kodu));
        if(bilgi->urunbilgileri.urun_kodu==0)
            printf("lutfen urun kodunu 0 girmeyiniz\n");

    }

    printf("urun fiyatini giriniz:");
    scanf("%d",&(bilgi->urunbilgileri.urun_fiyati));
}
void urun_yazdirma(genelbilgi *yazdirma)
{

    if(yazdirma->urunbilgileri.urun_adi&&yazdirma->urunbilgileri.urun_fiyati&&yazdirma->urunbilgileri.urun_kodu==0&&'\0')
    {
        printf("urunleri yazdirmak icin lutfen once urun ekleyiniz\n");

    }
    else
    {

        printf("urun adi= %s \t urun kodu= %d \t urun fiyati= %d TL\n",yazdirma->urunbilgileri.urun_adi
               ,yazdirma->urunbilgileri.urun_kodu
               ,yazdirma->urunbilgileri.urun_fiyati);
    }
}
void urun_silme(genelbilgi*silmeadresi,genelbilgi *silmekodu)
{
    int i,boyut;
    int *silboyut;

    silboyut=(&silmekodu);
    boyut=(*silboyut);

    for(i=0; i<=boyut; i++)
    {
        if(silmeadresi->urunbilgileri.urun_kodu==boyut)
        {
            strcpy(silmeadresi->urunbilgileri.urun_adi,"urun silinmistir");
            silmeadresi->urunbilgileri.urun_kodu='\0';
            silmeadresi->urunbilgileri.urun_fiyati='\0';

            printf("\nurun basariyla silinmistir\n");

            break;
        }
        else
        {
            silmeadresi++;
        }
    }
}
void urunlerin_sisteme_kaydi(genelbilgi *kayit)
{
    strcpy(kayit->urunbilgileri.urun_adi,"cips");
    kayit->urunbilgileri.urun_kodu=1;
    kayit->urunbilgileri.urun_fiyati=15;
    strcpy((kayit+1)->urunbilgileri.urun_adi,"kula");
    (kayit+1)->urunbilgileri.urun_kodu=2;
    (kayit+1)->urunbilgileri.urun_fiyati=10;
}
void urun_guncelleme(genelbilgi *bellekadres, genelbilgi *oncekikod)
{


    int i,boyut;
    int *gunboyut;

    gunboyut=(&oncekikod);
    boyut=(*gunboyut);

    for(i=0; i<=boyut; i++)
    {
        if(bellekadres->urunbilgileri.urun_kodu==oncekikod)
        {
            printf("degistirmek istedigin urunun ismini giriniz:");
            scanf("%s",&(bellekadres->urunbilgileri.urun_adi));

            printf("guncellemek istediginiz urunun kodunu giriniz:");
            scanf("%d",&(bellekadres->urunbilgileri.urun_kodu));

            printf("guncellemek istediginiz urunun fiyatini giriniz:");
            scanf("%d",&(bellekadres->urunbilgileri.urun_fiyati));

            printf("urun basariyla guncellenmistir\n");
            break;
        }
        else
        {
            ++bellekadres;
        }
    }
}
//-----------------------------------------VERESIYE DEFTERI MENUSU FONKSIYONLARI------------------------------------------------------
void musteri_kayit(genelbilgi *musterikayit)
{
    printf("\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\1\n");

    printf("musterinin adini giriniz:");
    scanf("%s",&(musterikayit->musteri_bilgileri.musteri_adi));

    printf("musterinin soyadini giriniz:");
    scanf("%s",&(musterikayit->musteri_bilgileri.musteri_soyadi));

    while(musterikayit->musteri_bilgileri.musteri_kodu==0)
    {
        printf("musteri kodunu giriniz:");
        scanf("%d",&(musterikayit->musteri_bilgileri.musteri_kodu));

        if(musterikayit->musteri_bilgileri.musteri_kodu==0)
            printf("lutfen musteri kodunu 0 girmeyiniz\n");
    }

    printf("musteri borcunu giriniz:");
    scanf("%d",&(musterikayit->musteri_bilgileri.musteri_borcu));
}
void musteri_listeleme(genelbilgi *musterilisteleme)
{

    if(musterilisteleme->musteri_bilgileri.musteri_adi&&musterilisteleme->musteri_bilgileri.musteri_soyadi&&musterilisteleme->musteri_bilgileri
            .musteri_kodu&&musterilisteleme->musteri_bilgileri.musteri_borcu==0&&NULL)
    {
        printf("musterileri listelemek icin lutfen once musteri ekleyiniz ekleyiniz\n");

    }
    else
    {

        printf("musteri adi= %s \t musteri soyadi= %s \t musteri borcu= %d \t musteri kodu= %d\n",musterilisteleme->musteri_bilgileri.musteri_adi
               ,musterilisteleme->musteri_bilgileri.musteri_soyadi
               ,musterilisteleme->musteri_bilgileri.musteri_borcu
               ,musterilisteleme->musteri_bilgileri.musteri_kodu);
    }
}
void musteri_guncelleme(genelbilgi *musteriguncelleme, genelbilgi *guncellemekod)
{
    int i,mboyutg;
    int *mgunboyut;

    mgunboyut=(&guncellemekod);
    mboyutg=(*mgunboyut);


    for(i=0; i<=mboyutg; i++)
    {
        if(musteriguncelleme->musteri_bilgileri.musteri_kodu==mboyutg)
        {
            printf("guncellemek istediginiz musterinin ismini giriniz:");
            scanf("%s",&(musteriguncelleme->musteri_bilgileri.musteri_adi));

            printf("guncellemek istediginiz musterinin soyadini giriniz:");
            scanf("%s",&(musteriguncelleme->musteri_bilgileri.musteri_soyadi));

            printf("guncellemek istediginiz musterinin kodunu giriniz:");
            scanf("%d",&(musteriguncelleme->musteri_bilgileri.musteri_kodu));

            printf("guncellemek istediginiz musterinin borcunu giriniz:");
            scanf("%d",&(musteriguncelleme->musteri_bilgileri.musteri_borcu));

            printf("\nmusteri basariyla guncellenmistir\n");
            break;
        }
        else
        {
            ++musteriguncelleme;

        }
    }
}
void musteri_silme(genelbilgi *musterisilme, genelbilgi *silmekod)
{
    int i,silboyut,*silmetut;

    silmetut=(&silmekod);
    silboyut=(*silmetut);

 musterisilme++;

    for(i=0; i<=silboyut; i++)
    {
        if((musterisilme->musteri_bilgileri.musteri_kodu)==silboyut)
        {
            strcpy(musterisilme->musteri_bilgileri.musteri_adi,"silinmistir");
            strcpy(musterisilme->musteri_bilgileri.musteri_soyadi,"silinmistir");
            musterisilme->musteri_bilgileri.musteri_borcu='\0';
            musterisilme->musteri_bilgileri.musteri_kodu='\0';

            printf("\nmusteri basariyla silinmistir\n");

            break;

        }
        else
        {
            musterisilme++;

        }
    }
}
void fis_olusturma(genelbilgi *fisolusturma)
{
    int gun,ay,yil;
    int i,urunsayisi;
    float kdv=0.08;
    float toplamkdv=0;
    int toplamfiyat=0;

    printf("lutfen bugunun tarihini AA-BB-CCCC seklinde giriniz:");
    scanf("%d-%d-%d",&gun,&ay,&yil);

    printf("lutfen fis'de goruntulemek istediginiz urun sayisini giriniz");
    scanf("%d",&urunsayisi);

    printf("\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3Gundar Market\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\3\n");
    printf("\t\tTarih:%d-%d-%d\n\n",gun,ay,yil);
    for(i=1; i<=urunsayisi; i++)
    {
        printf("%d-%s\t=%d TL\n",i,fisolusturma->urunbilgileri.urun_adi,fisolusturma->urunbilgileri.urun_fiyati);
        kdv=(fisolusturma->urunbilgileri.urun_fiyati)*kdv;
        toplamkdv=toplamkdv+kdv;
        toplamfiyat+=fisolusturma->urunbilgileri.urun_fiyati;
        fisolusturma++;


    }
    printf("------------------------------------");
    printf("\n\ntoplam kdv:\t%.1f krs\n",toplamkdv);
    printf("toplam fiyat:\t%d TL\n\n\n",toplamfiyat);
    printf("kasiyer:\t\t\tT***** B****\n");
    printf("\t\t\tIRSALIYE YERINE GECER\n");
    printf("\t\t\t\t<IMZA>\n");
}
//---------------------------------------------SATMA ISLEMLERI MENUSU FONKSIYON-------------------------------------------------------------

void urun_satma(genelbilgi *urunsatma, genelbilgi *satmakodu)
{
    int satboyut,*satp,i;

    satp=(&satmakodu);
    satboyut=(*satp);

    genelbilgi *urunkontrol;
    urunkontrol=urunsatma;

    for(i=0; i<=satboyut; i++)
    {
        if(urunkontrol->urunbilgileri.urun_kodu!=0)
        {
            if(urunsatma->urunbilgileri.urun_kodu==satboyut)
            {
                strcpy(urunsatma->urunbilgileri.urun_adi,"urun satilmistir\n");
                urunsatma->urunbilgileri.urun_kodu='\0';
                urunsatma->urunbilgileri.urun_fiyati='\0';

                printf("\nurun basariyla satilmistir\n");
            }
            else
            {

                ++urunsatma;

            }
        }
        else
        {
            ++urunkontrol;

        }
    }
    if(urunkontrol->urunbilgileri.urun_kodu==0)
    {
        printf("lutfen urun satmak icin once urun ekleyiniz\n");
    }

}

void tahmini_kar_hesabi(genelbilgi *karhesabi)
{
    int karkod,i,gelisfiyat,kar,gun,toplamkar;

    printf("tahmini kar hesaplamak istediginiz urunun kodunu giriniz:");
    scanf("%d",&karkod);

    for(i=0 ; i<karkod; i++)
    {
        if(karhesabi->urunbilgileri.urun_kodu==karkod)
        {
            printf("urunun karsiz fiyatini giriniz:");
            scanf("%d",&gelisfiyat);

            kar=karhesabi->urunbilgileri.urun_fiyati-gelisfiyat;

            printf("kac gunde elde ettiginiz kar'i hesaplamak istersiniz:");
            scanf("%d",&gun);

            toplamkar=kar*gun;

            printf("%d gunde elde edeceginiz toplam kar miktari=%d\n",gun,toplamkar);

        }
        else
        {
            karhesabi++;
        }
    }

}
void urun_iade(genelbilgi *iade,int iadekod,int iadefiyat, char iadeisim[15])
{
    int i;
    int iadekodf;

    printf("iade etmek istediginiz urunun kodunu giriniz:");
    scanf("%d",&iadekodf);

    for(i=0; i<iadekodf; i++)
    {
        if((iade+i)->urunbilgileri.urun_kodu==0||'\0')
        {

            if(iadekodf==iadekod)
            {
                strcpy((iade+i)->urunbilgileri.urun_adi,iadeisim);
                (iade+i)->urunbilgileri.urun_kodu=iadekod;
                (iade+i)->urunbilgileri.urun_fiyati=iadefiyat;

                printf("\nurun basarili bir sekilde iade edilmistir.\n\nBizi tercih ettiginiz icin tesekkur ederiz.\n");
            }
        }
    }
}


