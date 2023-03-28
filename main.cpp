#include <stdio.h>
#include "body.cpp"

int main()
{

    Isi_Tree tree1;
    infotype isi, Cari;
    int pilih, jmlNode;

    fflush(stdin);
    printf("Berapa jumlah node yang akan dibuat : ");
    scanf("%d", &jmlNode);

    Create_tree(tree1, jmlNode);
    fflush(stdin);
    printf("Tambahkan parent: ");
    scanf("%c", &isi);

    addParent(tree1, isi);

    while (true)
    {
        fflush(stdin);
        printf("1. Insert\n2. Search\n3. Traversal\n4. Delete\n5. Keluar\nPilih: ");
        scanf("%d", &pilih);
        switch (pilih)
        {
        case 1:
            fflush(stdin);
            printf("Masukkan karakter/isi: ");
            scanf("%c", &isi);
            addChild(tree1, isi);
            break;
        case 2:
            printf("Masukkan Data Yang ingin anda cari: ");
            scanf(" %c", &Cari);
            if (Search(tree1, Cari, jmlNode))
            {
                printf("true\n");
            }
            else
            {
                printf("false\n");
            }
            break;
        case 3:
            printf("Pilih yang ingin anda lakukan:\n1. Pre-Order\n2. Post-Order\n3. In-Order\n4. Level-Order\n");
            printf("Input: ");
            scanf("%d",&pilih);
            switch (pilih)
            {
                case 1:
                    PreOrder(tree1);
                    break;
                case 2:
                    PostOrder(tree1);
                    break;
                case 3:
                    InOrder(tree1);
                    break;
                case 4:
                    Level_order(tree1, jmlNode);
                    break;
            }
            break;
        case 4:
            printf("Masukkan data yang akan dihapus: ");
            scanf(" %c",&Cari);
            deleteNode(tree1,Cari);
            break;
        case 5:
            return 0;
            break;
        }
    }
    return 0;
}