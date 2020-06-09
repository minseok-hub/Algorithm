#include<iostream>

int number = 9;
int heap[9] = {7,6,5,8,3,5,9,1,6};

void heapify(int i) {
	
	int c = i;
	
	int root = (c - 1) / 2;
	
	if (heap[root] < heap[c]) {
		int temp = heap[root];
		heap[root] = heap[c];
		heap[c] = temp;
	}
	c = root;
	if (c != 0) heapify(c);
}


int main(void) {
	// ���� ���� 
	for (int i = 1; i < number; i++) {
		/*int c = i;
		do {
			
			int root = (c - 1) / 2;
			
			if (heap[root] < heap[c]) {
				int temp = heap[root];
				heap[root] = heap[c];
				heap[c] = temp;	
			}
			c = root;
		} while (c != 0);
		*/
		heapify(i);		
	}
	
	// ũ�⸦ �ٿ����鼭 �ݺ������� ���� ����.	
	for (int i = number - 1; i >= 0; i--) {
		int temp = heap[0];
		heap[0] = heap[i];
		heap[i] = temp;
		int root = 0;
		int c = 1;
		do {
			c = 2 * root + 1;
			// �ڽ� �߿� �� ū ���� ã��
			if (c < i - 1 && heap[c] < heap[c + 1]) {
				c++;
			}
			// ��Ʈ���� �ڽ��� ũ�ٸ� ��ȯ
			if (c < i && heap[root] < heap[c] ) {
				temp = heap[root];
				heap[root] = heap[c];
				heap[c] = temp;
			}
			root = c;
		} while (c < i);
	}
	// ��� ���
	for (int i = 0; i < number; i++) {
		printf("%d ", heap[i]);
	}
}