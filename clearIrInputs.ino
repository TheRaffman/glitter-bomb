void clearIrInputs()
{
    for (int i = 0; i < 5; i++)
    {
        if (irrecv.decode(&results)) // have we received an IR signal?
        {
            // Receive the next value
            irrecv.resume();
        }
    }
}
