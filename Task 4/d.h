int take(int num);
int take2(int num);
bool isStringBalanced(char** sentence, int size);

void push(node_t * head, int val);
void print_list(node_t * head);
int setValue(node_t * head ,int val, int index);
int returnVal(node_t * head, int index);
void merge(node_t * head, int start, int mid, int end);
void mergeSort(node_t * head, int start, int end );

struct Stack* createStack(unsigned capacity);
int isFull(struct Stack* stack);
int isEmpty(struct Stack* stack);
void pushToStack(struct Stack* stack, char item);
int pop(struct Stack* stack);
int isFit(struct Stack* stack, char bracket);
char peek(struct Stack* stack);
