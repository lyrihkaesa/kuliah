package src.entity;

public class Transaction {
    // nomor transaksi
    private String transactionId;

    // objek barang
    private Barang barang;

    // harga barang
    private Integer price;

    // kode barang
    private String itemId;

    // jumlah barang
    private Integer amount;

    public String getTransactionId() {
        return this.transactionId;
    }

    public void setTransactionId(String transactionId) {
        this.transactionId = transactionId;
    }

    public Barang getBarang() {
        return this.barang;
    }

    public void setBarang(Barang barang) {
        this.barang = barang;
    }

    public Integer getPrice() {
        if (this.price == null) {
            this.price = this.barang.getSellingPrice();
        }
        return this.price;
    }

    public void setPrice(Integer price) {
        if (this.barang.getSellingPrice() == null) {
            this.barang.setSellingPrice(price);
        }
        this.price = price;
    }

    public String getItemId() {
        if (this.itemId == null) {
            this.itemId = this.barang.getId();
        }
        return this.itemId;
    }

    public void setItemId(String itemId) {
        if (this.barang.getId() == null) {
            this.barang.setId(itemId);
        }
        this.itemId = itemId;
    }

    public Integer getAmount() {
        return this.amount;
    }

    public void setAmount(Integer amount) {
        this.amount = amount;
    }

}
