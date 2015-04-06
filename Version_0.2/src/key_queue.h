struct key_queue
{
	char array[512];
	int rear;
	int front;
};

void add_key(char next);
char remove_key();
int key_queue_is_empty();
void display_key_queue();
