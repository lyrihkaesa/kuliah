package src.model;

import java.util.List;

public interface PegawaiRepository {
    public int insert(PegawaiModel barang);

    public int update(PegawaiModel barang);

    public int delete(String nip);

    public PegawaiModel selectByNip(String nip);

    public List<PegawaiModel> selectAll();

}
