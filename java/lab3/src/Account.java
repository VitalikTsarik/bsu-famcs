import java.security.InvalidParameterException;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.LinkedList;

public class Account implements Iterator<Object>
{
    public static final String[] names =
            {
                    "name",
                    "accountNumber",
                    "currency",
                    "annualPrecentageRate",
                    "amount",
            };

    private ArrayList<Object> areas = null;

    public Account(String name, int accountNumber, String currency, int annualPrecentageRate, double amount)
    {
        areas.add(name);
        areas.add(accountNumber);
        areas.add(currency);
        areas.add(annualPrecentageRate);
        areas.add(amount);
    }

    public void withdraw(double amount)
    {
        if (amount > this.amount)
            throw new InvalidParameterException();
        this.amount -= amount;
    }

    public void deposit(double amount)
    {
        this.amount += amount;
    }

    public void chargeForPeriod(int years)
    {
        amount *= Math.pow(annualPrecentageRate, years);
    }

    public Iterator<Object> iterator() {
        reset();
        return this;
    }

    private int iterator_idx = 0;
    public void reset()
    {
        iterator_idx = 0;
    }

    @Override
    public boolean hasNext()
    {
        return iterator_idx < areas.size();
    }

    @Override
    public Object next()
    {
        if (iterator_idx < areas.size())
        {
            return areas[iterator_idx++];
        }
        reset();
        return null;
    }
}
