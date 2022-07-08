package src.repository;

import java.util.List;

import src.entity.Pegawai;

public interface PegawaiRepository {

    int insert(Pegawai barang);

    int update(Pegawai barang);

    int delete(String nip);

    Pegawai selectByNip(String nip);

    List<Pegawai> selectAll();

    Pegawai selectByNipAndPassword(String nip, String password);

}
