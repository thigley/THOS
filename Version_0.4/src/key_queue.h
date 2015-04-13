typedef struct key
{
	unsigned char scancode;
	char key;
}key;
struct key_queue
{
	key array[512];
	int rear;
	int front;
};

void add_key(unsigned char scan, char next);
key remove_key();
int key_queue_is_empty();
void display_key_queue();
