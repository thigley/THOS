struct key_queue KQ;

void add_key(unsigned char scan, char next)
{
	if((KQ.rear+1)%512==KQ.front) print("Queue Overflow");
	else KQ.array[KQ.rear++]=(key){.scancode = scan, .key = next};
	KQ.rear%=512;
}

key remove_key()
{
	key ret=KQ.array[KQ.front];
	if(key_queue_is_empty()) print("Queue Underflow"); 
	else KQ.front++;
	KQ.front%=512;
	return ret;
}

int key_queue_is_empty()
{
	return (KQ.front == KQ.rear)?1:0;
}

void display_key_queue()
{
	int i;
	for(i=KQ.front; i!=KQ.rear; i=(i+1)%512){
		print("char ->'");
		printchar(KQ.array[i].key);
		print("'\n");
	}
}
