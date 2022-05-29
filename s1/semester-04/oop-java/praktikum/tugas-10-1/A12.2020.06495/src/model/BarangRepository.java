package src.model;

import java.util.List;

public interface BarangRepository {
    public int insert(BarangModel barang);

    public int update(BarangModel barang);

    public int delete(String id);

    public BarangModel selectById(String id);

    public List<BarangModel> selectAll();

}
