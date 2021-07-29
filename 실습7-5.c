// 비트 벡터 집합 BitSet(헤더)
#ifndef ___BitSet
#define ___BitSet

typedef unsigned long BitSet; // 집합을 나타내는 자료형

#define BitSetNull (BitSet)0 // 공집합 
#define BitSetBits 32 // 유효 비트 수 
#define SetOf(no) ((BitSet)1 << (no)) // 잡헙 {no}

// 집합 s에 n이 있는지 확인
int IsMember(BitSet s, int n);

// 집합 s에 n을 추가
void Add(BitSet *s, int n);

// 집합 s에서 n을 삭제 
void Remove(BitSet *s, int n);

// 집합 s의 원소 개수를 반환 
int Size(BitSet s);
void Print(BitSet s);
void PrintLn(BitSet s);

#endif