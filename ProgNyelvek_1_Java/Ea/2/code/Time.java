class Time
{
    int hour;
    int minute;
    Time(int hour, int minute)
    {
        if (0 <= hour && hour < 24 && 0 <= minute && minute < 60)
        {
            this.hour = hour;
            this.minute = minute;
        }
        else
        {
            throw new IllegalArgumentException("Invalid time!");
        }
    }

    void aMinutePassed()
    {
        if(minute < 59)
        {
            ++minute;
        }
        else
        {
            minute = 0;
        }
    }
}