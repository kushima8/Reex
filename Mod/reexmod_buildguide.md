# Reex Mod ビルドガイド
## はじめに

![000](https://github.com/kushima8/Reex/assets/58157342/2c923e2b-3ef0-48cf-af4d-c82fc9649048)
![001](https://github.com/user-attachments/assets/ce31ee66-ab58-47e7-b266-4440c4df1737)
![002](https://github.com/user-attachments/assets/c7987ab7-7416-48ff-affc-c94ee0945c3b)
このたびはご購入いただきありがとうございます。<br>
本製品は組み立てが必要なキットです。<br>

作成にあたり不明点や疑問点などがありましたら、作者の[Twitterアカウント](https://twitter.com/kushima8)までご連絡ください。<br>
Twitter以外で連絡を頂いても対応が厳しいです。<br>
FF外からのリプライは通知オフにしており気づかない場合がこざいますご了承ください。<br>
それとDiscordのコミュニティなどで作者以外の方だけに不明点や疑問点などを質問することは非推奨です。<br>

写真は作成見本であり商品内容と同一ではありません。<br>
また仕様は予告なく変更されることがあります。<br>

完成品、未完成品にかかわらずヤフオク!やメルカリなどのネットオークションやフリマなどでの販売、転売は禁止しております。<br>
Boothや遊舎工房など作者本人が販売または委託している箇所以外で購入された場合、同梱品の不足や不良品の対応などの各種サポートが厳しいためです。<br>
もし発見した場合は対応します。<br>
ご理解のほどよろしくお願いいたします。<br>

各ビルドガイドの部品リストを参考に欠品がないか確認をお願いします。<br>
欠品や不良品などがありましたら確認したのちに対応いたします。<br>
ただし、海外など発送が難しい場合はこちらの指定する方法での一部返金などで対応します。<br>
あらかじめご了承ください。<br>

### ReexModの種類

ReexModはReex56とReex67に対応した拡張基板です。  
本機だけでは動作いたしません。  
必ずReex56かReex67どちらかをご用意ください。  
現在ReexModと呼ばれる拡張基盤は現在5種類位です。  
名称と詳細は下記画像を参考に確認してください。  
  
![001](https://github.com/kushima8/Reex/assets/58157342/cbe7db9d-ee5f-43ee-a784-e19502ed3e28)  
  
Boothなどで各種拡張基盤が一緒になった、ReexModセットを入手した場合は下記のパーツリストを参考に封入物の確認をお願いします。  
[ReexModセットパーツリスト](reexmodset_partslist.md)  
  
各種ReexModごとにビルドガイドを用意しております。  
組み立てはこちらをご確認ください。  
  
[①５キー拡張](5keymod_buildguide.md)  
[②３キー拡張](3keymod_buildguide.md)  
[③ロータリーエンコーダ拡張](rotaryencodermod_buildguide.md)  
[④１キー拡張](1keymod_buildguide.md)  
[⑤４キー拡張](4keymod_buildguide.md)  


### 用意しているファームウェアについて

* reex56mod_default.hex
  * [VIA対応(Remap)](https://github.com/kushima8/Reex/tree/main/Reex56/VIA/mod)
  * レイヤー4枚　
  * 1番レイヤーのみボールを一定動かすと3番レイヤー(マウスレイヤー)に自動遷移 
    ボールを停止して一定時間経過か、LCTRLと設定したマウスキーやスクロールキー以外を押下すると遷移前レイヤーに戻る  

* reex67mod_default.hex
  * [VIA対応(Remap)](https://github.com/kushima8/Reex/tree/main/Reex67/VIA/mod)
  * レイヤー4枚
  * 1番レイヤーのみボールを一定動かすと3番レイヤー(マウスレイヤー)に自動遷移  
    ボールを停止して一定時間経過か、LCTRLと設定したマウスキーやスクロールキー以外を押下すると遷移前レイヤーに戻る  
