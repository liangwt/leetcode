#define I_MIN(X, Y) (((X) < (Y)) ? (X) : (Y))
#define I_MAX(X, Y) (((X) > (Y)) ? (X) : (Y))

inline int i_array_len(int *array);
inline int i_string_len(char *s);
char *i_itoa(int v, char *str);
int i_max(int a, int b);