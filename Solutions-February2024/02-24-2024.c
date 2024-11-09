typedef struct Node {
    int val;
    struct Node *next;
} Node;

typedef struct {
    Node *head;
} Set;

Node* createNode(int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

Set* createSet() {
    Set* set = (Set*)malloc(sizeof(Set));
    if (!set) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    set->head = NULL;
    return set;
}

int contains(Set* set, int val) {
    Node* current = set->head;
    while (current) {
        if (current->val == val) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

void add(Set* set, int val) {
    if (!contains(set, val)) {
        Node* newNode = createNode(val);
        newNode->next = set->head;
        set->head = newNode;
    }
}

void freeSet(Set* set) {
    Node* current = set->head;
    while (current) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    free(set);
}

void dfs(int person, int** time, Set* secrets, int n, int* visited) {
    if (visited[person]) {
        return;
    }
    visited[person] = 1;
    add(secrets, person);

    for (int i = 0; i < n; i++) {
        if (time[person][i]) {
            dfs(i, time, secrets, n, visited);
        }
    }
}

int* findAllPeople(int n, int** meetings, int meetingsSize, int* meetingsColSize, int firstPerson, int* returnSize) {
    Set* secrets = createSet();
    int** time = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        time[i] = (int*)calloc(n, sizeof(int));
    }

    add(secrets, 0);
    add(secrets, firstPerson);

    for (int i = 0; i < meetingsSize; i++) {
        int person1 = meetings[i][0];
        int person2 = meetings[i][1];
        int t = meetings[i][2];

        time[person1][person2] = 1;
        time[person2][person1] = 1;
    }

    int* visited = (int*)calloc(n, sizeof(int));
    for (int t = 0; t < n; t++) {
        if (time[t]) {
            dfs(t, time, secrets, n, visited);
        }
    }

    free(visited);
    for (int i = 0; i < n; i++) {
        free(time[i]);
    }
    free(time);

    int* result = (int*)malloc(secrets->head->val * sizeof(int));
    Node* current = secrets->head->next;
    int index = 0;
    while (current) {
        result[index++] = current->val;
        current = current->next;
    }

    *returnSize = secrets->head->val;
    freeSet(secrets);

    return result;
}
