package src.repository;

import src.entity.Transaction;

public interface TransactionRepository {

    // insert
    int insert(Transaction transaction);

    // select
    String getLastId();
}
