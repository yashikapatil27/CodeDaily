int timeRequiredToBuy(int* tickets, int ticketsSize, int k) {
    int time = 0;

    while (tickets[k] > 0) {
        for (int i = 0; i < ticketsSize && tickets[k] > 0; i++) 
        {
            if (tickets[i] > 0) {
                tickets[i]--;
                time++;
            }
        }
    }

    return time;
}
