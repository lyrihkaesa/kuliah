package src.repository;

import src.entity.Suplayer;

import java.util.List;

public interface SuplayerRepository {

    int insert(Suplayer suplayer);

    int update(Suplayer suplayer);

    int delete(String kode);

    Suplayer selectByKode(String kode);

    List<Suplayer> selectAll();
}
