package src.repository;

import java.util.List;

import src.entity.Barang;

public interface BarangRepository {

    int insert(Barang barang);

    int update(Barang barang);

    int delete(String id);

    Barang selectById(String id);

    List<Barang> selectAll();

    List<Barang> selectAllByAmount(Integer amount);

}
