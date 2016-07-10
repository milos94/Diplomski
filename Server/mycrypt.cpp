#include "mycrypt.h"

MyCrypt::MyCrypt()
{
    //prng.GenerateBlock(key,sizeof(key));
    //prng.GenerateBlock(iv,sizeof(iv));
    std::string strKey="AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA";
    std::string strIV="AAAAAA";


    if(AES::MAX_KEYLENGTH < strKey.size()) strKey=strKey.substr(0,AES::MAX_KEYLENGTH);
    else if(AES::MAX_KEYLENGTH > strKey.size()) strKey+= std::string(AES::MAX_KEYLENGTH - strKey.size(),'*');
    memcpy(key,strKey.c_str(),AES::MAX_KEYLENGTH);


    if(AES::BLOCKSIZE <strIV.size()) strIV=strIV.substr(0,AES::BLOCKSIZE);
    else if(AES::BLOCKSIZE > strIV.size()) strIV+= std::string(AES::BLOCKSIZE - strIV.size(),'*');
    memcpy(iv,strIV.c_str(),AES::BLOCKSIZE);

    strKey.clear();
    strIV.clear();
    StringSource(key, AES::MAX_KEYLENGTH,true, new HexEncoder(new StringSink(strKey)));
    StringSource(iv, AES::BLOCKSIZE, true, new HexEncoder(new StringSink(strIV)));

    qDebug()<<strKey.c_str();
    qDebug()<<strIV.c_str();



}

QByteArray MyCrypt::encrypt(QByteArray data){
    try{
        CBC_Mode<AES>::Encryption e;
        e.SetKeyWithIV(key,sizeof(key),iv);
        std::string chiper1,chiper2;
        chiper1.clear();
        chiper2.clear();
        StringSource(data.data(),true,
                     new StreamTransformationFilter(e, new StringSink(chiper1),StreamTransformationFilter::PKCS_PADDING) );
        chiper2.clear();
        StringSource(chiper1,true,new HexEncoder(new StringSink(chiper2)));
        data.clear();
        data.append(chiper2.c_str());
        return data;
    }catch(const CryptoPP::Exception& e)
    {
      qDebug() << e.what();
    }
    return NULL;

}

QByteArray MyCrypt::decrypt(QByteArray data){
    try{
        CBC_Mode<AES>::Decryption d;
        d.SetKeyWithIV(key,sizeof(key),iv);
        std::string chiper1,chiper2;
        chiper1.clear();
        chiper2.clear();
        chiper2=data.data();
        StringSource(chiper2,true,new HexDecoder(new StringSink(chiper1)));
        qDebug()<<chiper1.c_str();
        chiper2.clear();
        StringSource(chiper1,true,
                     new StreamTransformationFilter(d, new StringSink(chiper2)));
        qDebug()<<chiper2.c_str();
        data.clear();
        data.append(chiper2.c_str());
        return data;
    }catch(const CryptoPP::Exception& e)
    {
        qDebug()<<e.what();
    }
    return NULL;
}

QByteArray MyCrypt::makeKey(){
    byte cKey[AES::MAX_KEYLENGTH];
    prng.GenerateBlock(cKey,sizeof(key));
    return QByteArray::fromRawData(reinterpret_cast<const char*>(cKey),sizeof(cKey));
}

QByteArray MyCrypt::makeIV(){
    byte cIV[AES::BLOCKSIZE];
    prng.GenerateBlock(cIV,sizeof(cIV));
    return QByteArray::fromRawData(reinterpret_cast<const char*>(cIV),sizeof(cIV));
}
