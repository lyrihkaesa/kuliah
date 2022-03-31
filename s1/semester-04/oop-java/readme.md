# Pemprograman Berbasi Obyek [PBO]

Standar dan style koding bahasa pemprograman `java`.

- Nama variabel mengunakan `snake_case` atau `camelCase`  
  p.s : Var. di Java bersifat **_case sensitive_**.

```java
// ❌ Nama class salah, seharusnya setiap karakter pertama setiap kata menggunakan huruf KAPITAL
public class namaFile {
    public static void main(String[] args) {
        //❌ Nama variabel salah, seharusnya menggunakan snake_case atau camelCase.
        int Level = 12;
        int UMUR = 12;
        double LevelDesimal = 13.2f;
    }
}


// ✅ Nama class benar karakter pertama setiap kata menggunakan huruf KAPITAL
public class NamaFile {
    public static void main(String[] args) {
        // ✅  Nama variabel benar menggunakan snake_case atau camelCase.
        int level = 12;
        double level_desimal = 13.2f;
    }
}

// ✅ Untuk nama fungsi gunakanlah "camelCase" daripada snake_case.
// ✅ Untuk nama constanta gunakan SNAKE_CASE dengan semua huruf KAPITAL.
```

## 🍱 Perangkat Lunak Pendukung

- [OpenJDK-17](https://jdk.java.net/17) - `Windows/x64` [📚 zip](https://download.java.net/java/GA/jdk17.0.2/dfd4a8d0985749f896bed50d7138ee7f/8/GPL/openjdk-17.0.2_windows-x64_bin.zip) `(sha256) 186216309`
- [Visual Studio Code [VS-Code]](https://code.visualstudio.com/Download) - `System Installer 64-bit`
- [Extension Pack for Java](https://marketplace.visualstudio.com/items?itemName=vscjava.vscode-java-pack) - `VSCode Extension`

## ⚒ Setting JDK PATH

- Cari `env` pada `search windows 10`,

![env](../pbo-java/z-lab-pengujian-img/win-search-env.png)

- Klik `Environment Variabel`
- Pada `System variables` cari `Path` lalu `Edit`
- Setelah itu klik `New`, copypaste path folder dari `..\jdk-1x.x.x\bin`
- Jika berada dibawah jangan lupa `Move Up` sampai bagian teratas.
- Lalu `OK` > `OK` > `OK`

---

- Setelah itu buka `CMD` lalu ketik, untuk mengecek apakah sudah terinstall dengan benar:

```cmd
java -version
openjdk version "17.0.2" 2022-01-18
OpenJDK Runtime Environment (build 17.0.2+8-86)
OpenJDK 64-Bit Server VM (build 17.0.2+8-86, mixed mode, sharing)

javac --version
17.0.2
```

## ⚙ setting.json

Pada `Visual Studio Code` silahkan install [Extension Pack for Java](https://marketplace.visualstudio.com/items?itemName=vscjava.vscode-java-pack), setelah itu abaikan jika dimintai untuk install `JDK` ulang.

Setelah itu `buat folder` lalu `open folder` ke `VSCode`, selanjutnya ubah `settingan VSCode` Anda dengan cara:

- Buka Command Pallete `CTRL + SHIFT + P` ketik `setting.json`, masukan kode `*json` dibawah ini ⤵.

```json
{
  // Java
  "java.configuration.runtimes": [
    // {
    //   "name": "JavaSE-15",
    //   "path": "C:\\Java\\openjdk-15.0.2_windows-x64_bin\\jdk-15.0.2"
    // },
    // {
    //   "name": "JavaSE-1.7",
    //   "path": "C:\\Java\\jdk-17_windows-x64_bin\\jdk-17.0.2"
    // },
    {
      "name": "JavaSE-17",
      "path": "C:\\Java\\openjdk-17.0.2_windows-x64_bin\\jdk-17.0.2",
      "default": true
    }
  ],
  "java.debug.settings.console": "externalTerminal"
}
```

- Setelah selesai setting coba buat file [HelloWorld.java](../pbo-java/belajar-java/HelloWorld.java) lalu tulis kode dibawah ini ⤵.

```java
public class HelloWorld {
    public static void main(String[] args) {
        System.out.println("Hello World!");
    }
}
```

- Lalu jalankan programnya, nanti akan tampil `> Hallo World!` pada `CMD` jika di `Windows`.
