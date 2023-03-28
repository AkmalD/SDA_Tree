#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "spesifikasi.h"

void Create_tree(Isi_Tree X, int Jml_Node)
{
    X[Jml_Node];
    X[0].info = ' ';
}

boolean IsEmpty(Isi_Tree P)
{
    if (P == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void addParent(Isi_Tree P, infotype X)
{
    P[1].ps_pr = 0;
    P[1].ps_nb = 0;
    P[1].ps_fs = 0;
    P[1].info = X;
    printf("%c menjadi parent/root. Parent berada pada Level 0", X);
    getch();
    system("cls");
}

void addChild(Isi_Tree P, infotype X)
{
    int idChild, idParent;
    nbtree pCur;
    if (!IsEmpty(P)) // child
    {
        printf("Pilih index child, masukkan index: ");
        scanf("%d", &idChild);
        P[idChild].info = X;
        printf("Pilih parent, masukkan index: ");
        scanf("%d", &idParent);
        P[idChild].ps_pr = idParent;
        P[idChild].ps_nb = 0;
        P[idChild].ps_fs = 0;
        if (P[idParent].ps_fs != 0)
        {
            pCur = P[P[idParent].ps_fs];
            if (P[idChild].ps_pr == pCur.ps_pr)
            {
                P[P[idParent].ps_fs].ps_nb = idChild;
            }
        }
        else
        {
            P[idParent].ps_fs = idChild;
        }
    }
    else
    {
        printf("Belum ada parent!");
        return;
    }
    getch();
    system("cls");
}

void PostOrder(Isi_Tree P)
{
    int pCur = 1;
    bool resmi = true;

    while (pCur != 0)
    {
        if (P[pCur].ps_fs != 0 && resmi)
        {
            pCur = P[pCur].ps_fs;
        }
        else
        {
            fflush(stdin);
            printf("%c ", P[pCur].info);
            if (P[pCur].ps_nb != 0)
            {
                pCur = P[pCur].ps_nb;
                resmi = true;
            }
            else
            {
                pCur = P[pCur].ps_pr;
                resmi = false;
            }
        }
    }
    printf("\n");
}

void PreOrder(Isi_Tree P)
{
    int Pcur;   // Posisi Node Aktif
    bool Resmi; // Sifat kunjungan resmi
    Pcur = 1;
    printf("%c", P[Pcur].info);
    Resmi = true;
    do
    {
        if (P[Pcur].ps_fs != 0 && Resmi)
        {
            Pcur = P[Pcur].ps_fs;
            printf("%c", P[Pcur].info);
        }
        else if (P[Pcur].ps_nb != 0)
        {
            Pcur = P[Pcur].ps_nb;
            printf("%c", P[Pcur].info);
            Resmi = true;
        }
        else
        {
            Pcur = P[Pcur].ps_pr;
            Resmi = false;
        }
    } while ((P[Pcur].ps_pr != 0));
    printf("\n");
}

void InOrder(Isi_Tree P)
{
    int Pcur;   // Posisi Node Aktif
    bool Resmi; // Sifat kunjungan resmi
    Pcur = 1;
    Resmi = true;
    while (Pcur != 0)
    {
        if (P[Pcur].ps_fs != 0 && Resmi)
        {
            Pcur = P[Pcur].ps_fs;
        }
        else
        {
            if (Resmi)
            {
                printf("%c", P[Pcur].info);
            }

            if (Pcur == P[P[Pcur].ps_pr].ps_fs)
            {
                printf("%c", P[P[Pcur].ps_pr].info);
            }

            if (P[Pcur].ps_nb != 0)
            {
                Pcur = P[Pcur].ps_nb;
                Resmi = true;
            }
            else
            {
                Pcur = P[Pcur].ps_pr;
                Resmi = false; // Numpang lewat
            }
        }
    }
    printf("\n");
}

boolean Search(Isi_Tree P, infotype X, int Jmlh)
{
    if (IsEmpty(P))
    {
        return false;
    }
    else
    {
        address idx = 1;
        while (idx <= Jmlh && P[idx].info != X)
        {
            if (P[idx].ps_fs != 0)
            {
                idx = P[idx].ps_fs;
            }
            else
            {
                idx = P[idx].ps_nb;
            }
        }
        if (idx <= Jmlh)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

void insQueue(Queue *q, int val)
{
    q->data[++q->rear] = val;
}

int delQueue(Queue *q)
{
    return q->data[++q->front];
}

void Level_order(Isi_Tree X, int jmlh)
{
    int Pcur = 1;
    Queue Q;
    Q.front = Q.rear = -1;
    printf("%d ", X[1].info);
    Pcur = X[1].ps_fs;
    insQueue(&Q, 0);
    for(int i = 0; i<jmlh; i++){
        while (Pcur != 0)
        {
            printf("%d ", X[Pcur].info);

            if (X[Pcur].ps_fs != 0)
            {
                insQueue(&Q, X[Pcur].ps_fs);
            }

            if (X[Pcur].ps_nb != 0)
            {
                Pcur = X[Pcur].ps_nb;
            }
            else
            {
                Pcur = delQueue(&Q);
            }
        }
    }
}

int findAddress(Isi_Tree P, infotype X)
{
    for (int i = 1; i <= jml_maks; i++)
    {
        if (P[i].info == X)
        {
            return i;
            break;
        }
    }
    return 0;
}

void deleteNode(Isi_Tree P, infotype X)
{
    int addr = findAddress(P, X);
    if (addr == 0)
    {
        printf("Node %c tidak ditemukan\n", X);
        return;
    }
    if (P[addr].ps_pr == 0)
    {
        printf("Tidak dapat menghapus root\n");
        return;
    }
    int parent = P[addr].ps_pr;
    int sibling = 0;
    if (P[parent].ps_fs == addr)
    {
        sibling = P[parent].ps_nb;
        P[parent].ps_fs = sibling;
    }
    else
    {
        int prev = P[parent].ps_fs;
        while (prev != 0 && P[prev].ps_nb != addr)
        {
            prev = P[prev].ps_nb;
        }
        if (prev == 0)
        {
            printf("Terjadi kesalahan\n");
            return;
        }
        sibling = P[prev].ps_nb;
        P[prev].ps_nb = P[addr].ps_nb;
    }
    P[addr].info = ' ';
    P[addr].ps_pr = 0;
    P[addr].ps_fs = 0;
    P[addr].ps_nb = 0;
    printf("Node %c berhasil dihapus\n", X);
    if (sibling == 0)
    {
        printf("Tidak ada sibling\n");
    }
    else
    {
        printf("Sibling node %c adalah %c\n", X, P[sibling].info);
    }
}
