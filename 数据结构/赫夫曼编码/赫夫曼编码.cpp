#include <iostream>
#include <cstdio>
#include <cctype>
#include <queue>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;

const int WORD_MAXN_LEN   = 100000;
const int WEIGHT_MAX_LEN  = 100;
const int   		    n = 60;

typedef struct
{
	unsigned int weight;
	unsigned int parent, lchild, rchild;
	
}HTNode, *HuffmanTree; 

typedef char **HuffmanCode; 

int  Word_len;
int  Huffmancode_len;
int  w[WEIGHT_MAX_LEN];
char Word[WORD_MAXN_LEN];
char WordToHuffmanCode[WORD_MAXN_LEN * 5];
char HuffmanCodeToWord[WORD_MAXN_LEN * 5];

void HuffmanCoding(HuffmanTree &HT, HuffmanCode &HC, int *w, int const &n);
void Select(HuffmanTree const &HT, int n, unsigned int &s1, unsigned int &s2);
void ShowCode(HuffmanCode const &HC, int const &n);
void GetWordWeight();
void TranslateWordsToHuffmanCode(HuffmanCode const &HC);
void ShowWordsToHuffmanCode(); 
void TranslateHuffmanCodeToWords(HuffmanTree const &HT);
void ShowHuffmanCodeToWords();

int main ()
{
	/*
		1、只能识别： 
			冒号，单引号，分号，句号，
			空格，回车，逗号，问号。
			 
		2、并且区分大小写 
	*/

	HuffmanTree HT = NULL;
	HuffmanCode HC = NULL;
	
	GetWordWeight();
	
	HuffmanCoding(HT, HC, w, n);
	
	ShowCode(HC, n);
	
	TranslateWordsToHuffmanCode(HC);
	
	ShowWordsToHuffmanCode();
	
	TranslateHuffmanCodeToWords(HT);
	
	ShowHuffmanCodeToWords();
	
	return 0;
}

void HuffmanCoding(HuffmanTree &HT, HuffmanCode &HC, int *w, int const &n)
{
	//Create_HuffmanTree
	
	int i = 0;
	HuffmanTree p   = NULL;
	unsigned int s1 = 0, s2 = 0;
	
	if(n <= 1)
		return;
	
	int m = 2 * n - 1;
	
	HT = new HTNode[m + 1];
	if(HT == NULL)
		exit(-1);

	memset(HT, 0, sizeof(HTNode) * (m + 1)); //按照节点清空 
	
	for(p = HT, i = 1; i <= n; ++i)
		p[i].weight = w[i - 1];
	
	for(int i = n + 1; i <= m; ++i)
	{
		Select(HT, i - 1, s1, s2);
		//左右子树的位置无所谓 
		HT[i].lchild  = s2; HT[s1].parent = i;
		HT[i].rchild  = s1; HT[s2].parent = i;
		HT[i].weight = HT[s1].weight + HT[s2].weight;
	}
	
	//Get_HuffmanCoding
	
	HC = new char *[n + 1];
	if(HC == NULL)
		exit(-1);
	
	char *cd = new char[n + 1];
	if(cd == NULL)
		exit(-1);
	
	cd[n - 1] = '\0';
	for(int i = 1; i <= n; ++i)
	{
		unsigned int p = 0, c = 0;
		int start = n - 1;
		for(p = HT[i].parent, c = i; p != 0; c = p, p = HT[p].parent)
		{
			if(HT[p].lchild == c)
				cd[--start] = '0';
			else
				cd[--start] = '1';
		}
		
		HC[i] = new char[n - start + 1];
		strcpy(HC[i], &cd[start]);
	}
	delete []cd;
}

void Select(HuffmanTree const &HT, int n, unsigned int &s1, unsigned int &s2)
{
	//挑选两个最小的节点，并返回位置 
	
	s1 = 0x3f3f3f3f; // 正无穷 
	s2 = s1;
	int s1pos = -1, s2pos = -1;
	
	for(int i = 1; i <= n; ++i)
	{
		if(HT[i].parent == 0)
		{
			if(HT[i].weight < s1)
			{
				s2    = s1;
				s1    = HT[i].weight;
				s2pos = s1pos;
				s1pos = i;
			}
			else if(HT[i].weight >= s1 && HT[i].weight < s2)
			{
				s2pos = i;
				s2 	  = HT[i].weight;
			}
		}
	}
	
	s1 = s1pos;
	s2 = s2pos;
	
	return;
}

void ShowCode(HuffmanCode const &HC, int const &n)
{
	//显示huffman编码 
	
	HuffmanCode p = HC;
	int 		i = 0;
	
	for(i = 1; i <= 26; ++i)
		printf("%c : %s\n", 'a' + i - 1, p[i]);
	
	for(i = 27; i <= 52; ++i)
		printf("%c : %s\n", 'A' + i - 27, p[i]);
	
	printf("空格 : %s\n", p[i++]);
	printf(", : %s\n", p[i++]);
	printf(". : %s\n", p[i++]);
	printf("\\n : %s\n", p[i++]);
	printf("? : %s\n", p[i++]);
	printf(": : %s\n", p[i++]);
	printf("\' : %s\n", p[i++]);
	printf("; : %s\n", p[i++]);
}

void GetWordWeight()
{
	//获得文章的字符权值
	char ch;
	
	printf("请输入一段文章，以EOF结尾：\n");
	while(1) 
	{
		ch = getchar();
		if(isalpha(ch))
		{
			if(isupper(ch))
				++w[ch - 'A' + 26];
			else
				++w[ch - 'a'];
		}
		else if(ch == ' ')
			++w[52];
		else if(ch == ',')
			++w[53];
		else if(ch == '.')
			++w[54];
		else if(ch == '\n')
			++w[55];
		else if(ch == '?')
			++w[56];
		else if(ch == ':')
			++w[57];
		else if(ch == '\'')
			++w[58];
		else if(ch == ';')
			++w[59];
			
		if(ch == EOF)
			break;
			
		Word[Word_len++] = ch;
	}
	
	return;
}

void TranslateWordsToHuffmanCode(HuffmanCode const &HC)
{
	//将文字转换为Huffman编码 
	
	int first = 1;
	for(int i = 0; i < Word_len; ++i)
	{
		int t = 0;
		if(isalpha(Word[i]))
		{
			if(isupper(Word[i]))
				t = Word[i] - 'A' + 27;
			else
				t = Word[i] - 'a' + 1;
		}
		else
		{
			if(Word[i] == ' ')
				t = 53;
			else if(Word[i] == ',')
				t = 54;
			else if(Word[i] == '.')
				t = 55;
			else if(Word[i] == '\n')
				t = 56;
			else if(Word[i] == '?')
				t = 57;
			else if(Word[i] == ':')
				t = 58;
			else if(Word[i] == '\'')
				t = 59;
			else if(Word[i] == ';')
				t = 60;
		}
		
		if(first)
		{ 
			first = 0;
			strcpy(WordToHuffmanCode, HC[t]);
		} 
		else
			strcat(WordToHuffmanCode, HC[t]);
	}
	
	Huffmancode_len = strlen(WordToHuffmanCode);
	
	return;
}

void ShowWordsToHuffmanCode()
{
	//显示文字转换后的Huffman编码 
	
	printf("\n文字转换为的Huffman编码：\n");
	puts(WordToHuffmanCode);
	
	return;
}

void TranslateHuffmanCodeToWords(HuffmanTree const &HT)
{
	//将编码过的文字转换为原始文字
	
	int    		i = 0, m = 2 * n - 1;
	int    		t = m;
	char	Tchar = '\0';
	HuffmanTree p = HT;
	
	Word_len	  = 0;
	while(i < Huffmancode_len)
	{
		t = m;
		p = HT;
		//当该节点没有左右子树则结束循环 
		while(!(p[t].lchild == 0 && p[t].rchild == 0))
		{
			if(WordToHuffmanCode[i] == '0')
				t = p[t].lchild;
			else
				t = p[t].rchild;
			++i;
		}
		
		if(1 <= t && t <= 26)
			Tchar = t + 'a' - 1;
		else if(27 <= t && t <= 52)
			Tchar = t + 'A' - 27;
		else
		{
			if(t == 53)
				Tchar = ' ';
			else if(t == 54)
				Tchar = ',';
			else if(t == 55)
				Tchar = '.';
			else if(t == 56)
				Tchar = '\n';
			else if(t == 57)
				Tchar = '?';
			else if(t == 58)
				Tchar = ':';
			else if(t == 59)
				Tchar = '\'';
			else if(t == 60)
				Tchar = ';';
		}
		
		HuffmanCodeToWord[Word_len++] = Tchar;
	}
	
	HuffmanCodeToWord[Word_len] = '\0';
}

void ShowHuffmanCodeToWords()
{
	//显示Huffman编码转换后的文字 
	
	printf("\nHuffman编码转换后的文字：\n");
	puts(HuffmanCodeToWord);
	
	return;
}
