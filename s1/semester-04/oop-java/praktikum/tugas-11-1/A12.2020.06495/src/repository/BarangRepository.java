package src.repository;

import java.util.List;

import src.entity.Barang;

public interface BarangRepository {
    public int insert(Barang barang);

    public int update(Barang barang);

    public int delete(String id);

    public Barang selectById(String id);

    public List<Barang> selectAll();

}
