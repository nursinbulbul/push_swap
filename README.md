*This project has been created as part of the 42 curriculum by nbulbul, aykale.*

## 📋 Description

**Push_swap**, verilen bir tam sayı yığınını (stack), kısıtlı bir komut seti kullanarak ve mümkün olan en az hamleyle sıralamayı amaçlayan bir algoritma projesidir. Proje, algoritma karmaşıklığı ($O(n^{2})$, $O(n\sqrt{n})$, $O(n \log n)$) ve veri yapısı yönetimi üzerine odaklanır. Program, yığını sıralamak için gereken operasyon dizisini standart çıktıya basar.

## 🛠️ Instructions

### Compilation

Proje, kök dizinde bulunan `Makefile` kullanılarak derlenir.

```bash
make          # push_swap programını derler
make clean    # nesne dosyalarını siler
make fclean   # tüm çıktıları temizler

```

### Execution

Program, bir tam sayı listesi ve opsiyonel strateji bayrakları ile çalışır:

```bash
./push_swap 3 2 10 5
./push_swap --simple 3 2 10 5 6 1     # O(n^2) algoritmasını zorlar
./push_swap --medium 3 2 10 5 6 1     # O(n*sqrt(n)) algoritmasını zorlar
./push_swap --complex 3 2 10 5 6 1   # O(n log n) algoritmasını zorlar
./push_swap --bench 3 2 10 5 6 1     # Performans metriklerini gösterir

```

## 🧠 Algorithms & Rationale

Projede, subject gereği farklı düzensizlik (disorder) seviyelerine göre optimize edilmiş dört strateji uygulanmıştır:

1. **Simple (\(O(n^{2})\)):** Düşük veri setleri veya düşük düzensizlik (disorder < 0.2) durumlarında **Selection Sort** adaptasyonu kullanılır. Küçük boyutlu veri kümelerinde düşük operasyon maliyeti ve sade yapı hedeflenir.
2. **Medium ($O(n\sqrt{n})$):** Orta seviye düzensizlik (0.2 ≤ disorder < 0.5) için **Chunk-based** sıralama tercih edilmiştir. Yığın $\sqrt{n}$ parçaya bölünerek yönetilebilir bloklar halinde sıralanır.
3. **Complex ($O(n \log n)$):** Yüksek düzensizlik (disorder ≥ 0.5) durumlarında **Radix Sort**  adaptasyonu kullanılır. Bit düzeyinde işlem yaparak büyük veri setlerinde kararlı bir performans sunar.
4. **Adaptive:** Başlangıçta hesaplanan **disorder metric** değerine göre yukarıdaki üç algoritmadan en uygun olanı çalışma zamanında (runtime) otomatik olarak seçer.

## 🤝 Contributions (Görev Dağılımı)

| Member | Contributions |
| --- | --- |
| **nbulbul** | Algoritma geliştirmeleri: Selection Sort, Chunk-based Sorting, Radix Sort. |
| **aykale** | Adaptive strateji tasarımı, yığın operasyonlarının (sa, pb, ra vb.) implementasyonu. |
| **Ortak** | `main.c`, `utils.c`, `parsing.c`, `--bench` modu geliştirme ve test süreçleri. |

## 🤖 Resources & AI Usage

* **Resources:** Algoritma karmaşıklığı için Bilgisayar Kavramları ve diğer Youtube video kaynakları ve Big-O notasyonu için çeşitli makaleler referans alınmıştır.
* **AI Usage:** AI araçları algoritma algılarının oluşturulmasında ve bench işlemlerinde yönlendirme olarak kullanılmıştır.

---

### Projenin Püf Noktaları (Not):

* **Disorder Metric:** Kodun içinde $mistakes / total\_pairs$ formülünü kullanarak hesaplama yapıyoruz.
* **Bench Mode:** `--bench` bayrağı ile toplam operasyon sayısı ve kullanılan strateji `stderr` üzerinden takip edilebilir.