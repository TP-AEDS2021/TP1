# 1 "./tads/lista_processos/lista_processo.h"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "./tads/lista_processos/lista_processo.h"



# 1 "d:\\facul\\aeds\\tp_1\\tads\\processo\\processo.h" 1



# 1 "d:\\src\\mingw\\include\\time.h" 1 3
# 33 "d:\\src\\mingw\\include\\time.h" 3
       
# 34 "d:\\src\\mingw\\include\\time.h" 3
# 45 "d:\\src\\mingw\\include\\time.h" 3
# 1 "d:\\src\\mingw\\include\\sys\\types.h" 1 3
# 34 "d:\\src\\mingw\\include\\sys\\types.h" 3
       
# 35 "d:\\src\\mingw\\include\\sys\\types.h" 3



# 1 "d:\\src\\mingw\\include\\_mingw.h" 1 3
# 55 "d:\\src\\mingw\\include\\_mingw.h" 3
       
# 56 "d:\\src\\mingw\\include\\_mingw.h" 3
# 66 "d:\\src\\mingw\\include\\_mingw.h" 3
# 1 "d:\\src\\mingw\\include\\msvcrtver.h" 1 3
# 35 "d:\\src\\mingw\\include\\msvcrtver.h" 3
       
# 36 "d:\\src\\mingw\\include\\msvcrtver.h" 3
# 67 "d:\\src\\mingw\\include\\_mingw.h" 2 3






# 1 "d:\\src\\mingw\\include\\w32api.h" 1 3
# 35 "d:\\src\\mingw\\include\\w32api.h" 3
       
# 36 "d:\\src\\mingw\\include\\w32api.h" 3
# 59 "d:\\src\\mingw\\include\\w32api.h" 3
# 1 "d:\\src\\mingw\\include\\sdkddkver.h" 1 3
# 35 "d:\\src\\mingw\\include\\sdkddkver.h" 3
       
# 36 "d:\\src\\mingw\\include\\sdkddkver.h" 3
# 60 "d:\\src\\mingw\\include\\w32api.h" 2 3
# 74 "d:\\src\\mingw\\include\\_mingw.h" 2 3
# 39 "d:\\src\\mingw\\include\\sys\\types.h" 2 3
# 139 "d:\\src\\mingw\\include\\sys\\types.h" 3
  
# 139 "d:\\src\\mingw\\include\\sys\\types.h" 3
 typedef long __time32_t;
  typedef long long __time64_t;
# 149 "d:\\src\\mingw\\include\\sys\\types.h" 3
   typedef __time32_t time_t;
# 46 "d:\\src\\mingw\\include\\time.h" 2 3
# 115 "d:\\src\\mingw\\include\\time.h" 3
struct timespec
{







  __time64_t tv_sec;
  long tv_nsec;
};


struct __mingw32_expanded_timespec
{





  union
  {



    __time64_t __tv64_sec;
    __time32_t __tv32_sec;
    time_t tv_sec;
  };
  long tv_nsec;
};
# 155 "d:\\src\\mingw\\include\\time.h" 3


extern inline __attribute__((__gnu_inline__)) __attribute__((__always_inline__))







struct __mingw32_expanded_timespec *mingw_timespec( struct timespec *__tv )
{ return (struct __mingw32_expanded_timespec *)(__tv); }


# 178 "d:\\src\\mingw\\include\\time.h" 3
# 1 "d:\\src\\mingw\\lib\\gcc\\mingw32\\6.3.0\\include\\stddef.h" 1 3 4
# 216 "d:\\src\\mingw\\lib\\gcc\\mingw32\\6.3.0\\include\\stddef.h" 3 4
typedef unsigned int size_t;
# 328 "d:\\src\\mingw\\lib\\gcc\\mingw32\\6.3.0\\include\\stddef.h" 3 4
typedef short unsigned int wchar_t;
# 179 "d:\\src\\mingw\\include\\time.h" 2 3




typedef long clock_t;

struct tm
{




  int tm_sec;
  int tm_min;
  int tm_hour;
  int tm_mday;
  int tm_mon;
  int tm_year;
  int tm_wday;
  int tm_yday;
  int tm_isdst;
};



 __attribute__((__cdecl__)) __attribute__((__nothrow__)) clock_t clock (void);
# 214 "d:\\src\\mingw\\include\\time.h" 3
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) time_t time (time_t *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) double difftime (time_t, time_t);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) time_t mktime (struct tm *);
# 228 "d:\\src\\mingw\\include\\time.h" 3
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) char *asctime (const struct tm *);





 __attribute__((__cdecl__)) __attribute__((__nothrow__)) char *ctime (const time_t *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) struct tm *gmtime (const time_t *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) struct tm *localtime (const time_t *);


 __attribute__((__cdecl__)) __attribute__((__nothrow__))
size_t strftime (char *, size_t, const char *, const struct tm *);


extern __attribute__((__cdecl__)) __attribute__((__nothrow__)) void _tzset (void);


extern __attribute__((__cdecl__)) __attribute__((__nothrow__)) void tzset (void);


 __attribute__((__cdecl__)) __attribute__((__nothrow__)) char *_strdate (char *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) char *_strtime (char *);






 __attribute__((__cdecl__)) __attribute__((__nothrow__)) __time64_t _time64( __time64_t *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) __time64_t _mktime64 (struct tm *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) char *_ctime64 (const __time64_t *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) struct tm *_gmtime64 (const __time64_t *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) struct tm *_localtime64 (const __time64_t *);
# 344 "d:\\src\\mingw\\include\\time.h" 3
extern __attribute__((__cdecl__)) __attribute__((__nothrow__)) int *__p__daylight (void);
extern __attribute__((__cdecl__)) __attribute__((__nothrow__)) long *__p__timezone (void);
extern __attribute__((__cdecl__)) __attribute__((__nothrow__)) char **__p__tzname (void);

extern __attribute__((__dllimport__)) int _daylight;
extern __attribute__((__dllimport__)) long _timezone;
extern __attribute__((__dllimport__)) char *_tzname[2];
# 381 "d:\\src\\mingw\\include\\time.h" 3
extern __attribute__((__dllimport__)) int daylight;
extern __attribute__((__dllimport__)) long timezone;
extern __attribute__((__dllimport__)) char *tzname[2];
# 407 "d:\\src\\mingw\\include\\time.h" 3
__attribute__((__cdecl__)) __attribute__((__nothrow__))
int nanosleep( const struct timespec *, struct timespec * );
# 428 "d:\\src\\mingw\\include\\time.h" 3

# 440 "d:\\src\\mingw\\include\\time.h" 3



 __attribute__((__cdecl__)) __attribute__((__nothrow__)) wchar_t *_wasctime (const struct tm *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) wchar_t *_wstrdate (wchar_t *);
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) wchar_t *_wstrtime (wchar_t *);






 __attribute__((__cdecl__)) __attribute__((__nothrow__)) wchar_t *_wctime64 (const __time64_t *);
# 466 "d:\\src\\mingw\\include\\time.h" 3
 __attribute__((__cdecl__)) __attribute__((__nothrow__)) wchar_t *_wctime (const time_t *);
# 495 "d:\\src\\mingw\\include\\time.h" 3
 __attribute__((__cdecl__)) __attribute__((__nothrow__))
size_t wcsftime (wchar_t *, size_t, const wchar_t *, const struct tm *);


# 5 "d:\\facul\\aeds\\tp_1\\tads\\processo\\processo.h" 2



# 7 "d:\\facul\\aeds\\tp_1\\tads\\processo\\processo.h"
typedef struct Tprocesso
{
  unsigned long PID;
  int prioridade;
  struct tm *horario_criacao;
} Processo;


Processo *inicializa_processo(Processo *);


void imprime_processo(Processo *);


unsigned long get_PID(Processo *);

void set_PID(Processo *, unsigned long pid);

int get_prioridade(Processo *);

void set_prioridade(Processo *, int);

struct tm *get_horario_criacao(Processo *);

void set_horario_criacao(Processo *, struct tm *);

void imprime_processo_arquivo(FILE *, Processo *);
# 5 "./tads/lista_processos/lista_processo.h" 2

typedef long int cursor;

typedef struct Tcelula {
  Processo *processo;
  cursor ant;
  cursor prox;
} Celula;

typedef struct Tlista {
  cursor primeiro;
  cursor primeira_disponivel;
  cursor ultimo;
  long int numCelOcupadas;
  Celula *plista;
  long int tam;
} Lista;

Celula *inicializa_celula(Celula *, Processo *);
Lista * inicializa_lista(Lista *lista,long int tamanho);
void adiciona_celula(Lista *lista, Celula *celula);
void remove_primeiro(Lista *lista);
void imprime_lista(Lista *lista);
void num_celulas_ocupadas(Lista *lista);
long int get_celulas_ocupadas(Lista *lista);
