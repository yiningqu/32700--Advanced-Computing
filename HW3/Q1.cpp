
SinglyLinkedListNode* removeNodes(SinglyLinkedListNode* listHead, int x) {
    SinglyLinkedListNode* dummy = new SinglyLinkedListNode(0);
    dummy->next = listHead;

    SinglyLinkedListNode* prev = dummy;
    SinglyLinkedListNode* current = listHead;

    while (current != nullptr){
        if (current->data > x){
            prev->next = current->next;
            SinglyLinkedListNode* temp = current;
            current = current->next;
            delete temp;
        }else{
            prev = current;
            current = current->next;
        }
    }
    SinglyLinkedListNode* newHead = dummy->next;
    delete dummy;
    return newHead;
}