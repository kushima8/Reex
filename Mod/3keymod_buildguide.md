# 3キー拡張 ビルドガイド

## はじめに
3キー拡張はReex56またはReex67の下記画像赤枠の位置へのみ取り付け可能です。  
※Reex67とReex56の差異はキースイッチ部分だけであり拡張取り付け部分は同一であるため、Reex67の画像は省略しております。  
  
![000](https://github.com/kushima8/Reex/assets/58157342/13be064b-57c3-4dbb-8dd5-9d1bbb00b665)
![001](https://github.com/kushima8/Reex/assets/58157342/5f92a57c-bd51-4e64-9fd8-7b81c8c0ed7b)
![011](https://github.com/kushima8/Reex/assets/58157342/4adf6a09-d9e2-476c-b168-c559ab927770)
キー拡張は同一側に一つのみ増設可能です。  
ロータリーエンコーダ拡張、トラックボール拡張との同一側での併用は可能です。  
（例：○ 右側 1キー拡張＋ロータリーエンコーダ拡張、左側 3キー拡張＋トラックボール拡張  
　　：✕ 右側 ロータリーエンコーダ拡張＋トラックボール拡張　左側 拡張なし   
　　：✕ 右側 拡張なし　左側  ロータリーエンコーダ拡張＋トラックボール拡張 ）  

## 部品

|名称|数量|備考|
|----|:---:|----|
|PCB|1枚|
|ボトムプレート|1枚|PCBと一体　捻って外せます|
|M2 2mmスペーサー(CB-2002E)|2個|丸型中空|
|M2 7.5mmスペーサー(ARB-2007.5E)|2個|丸型両メネジ|
|M2 11mmスペーサー(ARB-20011E)|3個|丸型両メネジ|
|M2 4mmネジ|5本|
|M2 10mmネジ|5本|
|Kailh PCB ソケット(Cherry MX用)|3個|
|ダイオード(1N4148W)|5個|

### 別途、購入が必ず必要なもの
以下の部品は別途購入してください。

|名称|数量|備考|
|----|:---:|----|
|キースイッチ(Cherry MX互換)|3個|
|キースイッチ(Kailh Choc V1互換)|3個|Lofree Ghost switchも可|
|キーキャップ(Cherry MX互換)|3個|
|キーキャップ(Kailh Choc V1互換)|3個|
|電線|4本|
|スルーホール用テストワイヤ|4本|サンハヤト スルーホール用テストワイヤー TTW-200など|
|ゴム足|1個|

### オプション
以下の部品はオプション品です。 

|名称|数量|備考|
|----|:---:|----|
|Kailh PCB ソケット(Kailh Choc V1用)|3個|

## 組み立て
※拡張基板はリバーシブルPCBとなっております。  
　使用する位置とキーキャップの大きさにより実装面が変わります。  
　適宜説明内容を読み替えてご覧ください。  

* 1.7Pinコンスルー加工と差し替え
  * Reex基盤本体とトラックボール用センサーボードの接続に用いている8Pinコンスルーをニッパーなどを使い7Pinコンスルーに加工します。  
  * 8Pinコンスルーの右から三番目のPinをニッパーなどで切除してください。
  
  ![000](https://github.com/kushima8/Reex/assets/58157342/e855b6f8-ed85-4577-9491-9a3f3db513a9)
  * Reex基盤本体の接続部分の右から三番目のPin（F6）に7PinコンスルーのPinが無くなっている部分が来るようにセンサボードと接続するようにしてください。
  
  ![001](https://github.com/kushima8/Reex/assets/58157342/729b627e-7b1c-4b00-ad64-1256854cb8d2)
* 2.ファームウェアの書き込み
  * [reex56mod_default.hex](https://github.com/kushima8/Reex/tree/main/Reex56/HEX/mod/reex56mod_default.hex) or [reex67mod_default.hex](https://github.com/kushima8/Reex/tree/main/Reex67/HEX/mod/reex56mod_default.hex)を指定してファームウェアを書き込んでください。
* 3.ダイオードのはんだ付け
  * PCB裏面のダイオード取り付け箇所の片側にあらかじめはんだを盛ります。  
  * その後、線が書いてある方を右(三角形の頂点の先に縦棒がある方)にセットします。
  * ダイオードをピンセットで持ちつつ、あらかじめはんだを盛った箇所をはんだごてで加熱して片側だけはんだ付けを行います。  
  * 片側のはんだ付けが完了後、もう片方もはんだ付けを行ってください。
* 4.Kailh PCB ソケット(Cherry MX用)/Kailh PCB ソケット(Kailh Choc V1用)のはんだ付け
  * PCB裏面のソケット取り付け箇所にあらかじめはんだを盛ります。  
  * 中央の穴に干渉しないようにソケットをPCB裏面に設置しはんだ付けを行ってください。  
* 5.本体への取り付け
  * Reex本体のボトムプレートを外します。  
  * 画像赤枠の部分に  
  　・拡張基盤  
  　・2mmスペーサー  
  　・Reex本体基盤  
  　・7.5mmスペーサー  
  となるようにセットし、上から10mmネジで固定してください。  
  その後青枠の部分に  
  　・拡張基盤  
  　・11mmスペーサー  
  となるようにセットし、上から10mmネジで固定してください。  
     
  ![002](https://github.com/kushima8/Reex/assets/58157342/04f533cc-cad8-4fc5-b013-d7c2864703c7)
  ![012](https://github.com/kushima8/Reex/assets/58157342/ad7381e9-84b1-4c5e-9eaa-d6ed69cfa715)
* 6.疎通テスト
  * 拡張基盤とReex本体基盤をテストワイヤで繋いでください。
  * TTW-200であればスルーホールに差し込むだけで接続できます。
  * 接続箇所は拡張基盤の印字とReex本体基盤の拡張取り付け部位近くにある印字が合うようにしてください。
  * Reex本体基盤の複数同じ印字がありますが、どちらに刺しても問題ありません。
  * 配線に関しては下記が画像を参考にしてください。
     
  ![003](https://github.com/kushima8/Reex/assets/58157342/a9aae595-8347-4de2-82c6-530610e11b29)
  ![013](https://github.com/kushima8/Reex/assets/58157342/2b6d489e-3de4-4b38-88c2-5ac5f2c6153f)
  * 接続後、キースイッチを取り付け入力可能かテストを行ってください。
  * 問題なければボトムプレートを配置し、4mmネジで固定してください。
* 7.電線のはんだ付け
  * この工程を行うと拡張基盤の取り外しが困難になります。
  * テストワイヤで接続した状態で、十分操作感などを確かめ変更の余地がないと確認後、この工程に進むようにしてください。
  * テストワイヤを外し電線と入れ替えるような形で拡張基板と本体基盤にはんだ付けを行い接続してください。

組み立ての手順は、以上です。
