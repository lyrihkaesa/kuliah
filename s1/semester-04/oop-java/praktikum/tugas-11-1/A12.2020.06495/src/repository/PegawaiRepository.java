package src.repository;

import java.util.List;

import src.entity.Pegawai;

public interface PegawaiRepository {
    public int insert(Pegawai barang);

    public int update(Pegawai barang);

    public int delete(String nip);

    public Pegawai selectByNip(String nip);

    public List<Pegawai> selectAll();

}
