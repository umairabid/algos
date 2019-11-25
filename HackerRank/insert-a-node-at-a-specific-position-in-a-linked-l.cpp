SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* head, int data, int position) {
    int cursor = 0;

    SinglyLinkedListNode* node = head;
    SinglyLinkedListNode* prev = nullptr;
    SinglyLinkedListNode* newNode = new SinglyLinkedListNode(data);

    while(cursor < position) {
        prev = node;
        node = node->next;
        cursor++;
    }

    
    if(node != nullptr && prev != nullptr) {
        cout << "case 1";
        newNode->next = node;
        prev->next = newNode;
        return head;
    } else if(node == nullptr && prev != nullptr) {
        cout << "case 2";
        prev->next = newNode;
        return head;
    } else if(node != nullptr && prev == nullptr) {
        cout << "case 3";
        newNode->next = node;
        return newNode;
    } else {
        cout << "case 4";
        return newNode;
    }
    
}