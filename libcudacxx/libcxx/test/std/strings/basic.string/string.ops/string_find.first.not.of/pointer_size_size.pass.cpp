//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// <string>

// size_type find_first_not_of(const charT* s, size_type pos, size_type n) const;

#include <string>
#include <cassert>

#include "test_macros.h"
#include "min_allocator.h"

template <class S>
void
test(const S& s, const typename S::value_type* str, typename S::size_type pos,
     typename S::size_type n, typename S::size_type x)
{
    assert(s.find_first_not_of(str, pos, n) == x);
    if (x != S::npos)
        assert(pos <= x && x < s.size());
}

template <class S>
void test0()
{
    test(S(""), "", 0, 0, S::npos);
    test(S(""), "irkhs", 0, 0, S::npos);
    test(S(""), "kante", 0, 1, S::npos);
    test(S(""), "oknlr", 0, 2, S::npos);
    test(S(""), "pcdro", 0, 4, S::npos);
    test(S(""), "bnrpe", 0, 5, S::npos);
    test(S(""), "jtdaefblso", 0, 0, S::npos);
    test(S(""), "oselktgbca", 0, 1, S::npos);
    test(S(""), "eqgaplhckj", 0, 5, S::npos);
    test(S(""), "bjahtcmnlp", 0, 9, S::npos);
    test(S(""), "hjlcmgpket", 0, 10, S::npos);
    test(S(""), "htaobedqikfplcgjsmrn", 0, 0, S::npos);
    test(S(""), "hpqiarojkcdlsgnmfetb", 0, 1, S::npos);
    test(S(""), "dfkaprhjloqetcsimnbg", 0, 10, S::npos);
    test(S(""), "ihqrfebgadntlpmjksoc", 0, 19, S::npos);
    test(S(""), "ngtjfcalbseiqrphmkdo", 0, 20, S::npos);
    test(S(""), "", 1, 0, S::npos);
    test(S(""), "lbtqd", 1, 0, S::npos);
    test(S(""), "tboim", 1, 1, S::npos);
    test(S(""), "slcer", 1, 2, S::npos);
    test(S(""), "cbjfs", 1, 4, S::npos);
    test(S(""), "aqibs", 1, 5, S::npos);
    test(S(""), "gtfblmqinc", 1, 0, S::npos);
    test(S(""), "mkqpbtdalg", 1, 1, S::npos);
    test(S(""), "kphatlimcd", 1, 5, S::npos);
    test(S(""), "pblasqogic", 1, 9, S::npos);
    test(S(""), "arosdhcfme", 1, 10, S::npos);
    test(S(""), "blkhjeogicatqfnpdmsr", 1, 0, S::npos);
    test(S(""), "bmhineprjcoadgstflqk", 1, 1, S::npos);
    test(S(""), "djkqcmetslnghpbarfoi", 1, 10, S::npos);
    test(S(""), "lgokshjtpbemarcdqnfi", 1, 19, S::npos);
    test(S(""), "bqjhtkfepimcnsgrlado", 1, 20, S::npos);
    test(S("eaint"), "", 0, 0, 0);
    test(S("binja"), "gfsrt", 0, 0, 0);
    test(S("latkm"), "pfsoc", 0, 1, 0);
    test(S("lecfr"), "tpflm", 0, 2, 0);
    test(S("eqkst"), "sgkec", 0, 4, 1);
    test(S("cdafr"), "romds", 0, 5, 0);
    test(S("prbhe"), "qhjistlgmr", 0, 0, 0);
    test(S("lbisk"), "pedfirsglo", 0, 1, 0);
    test(S("hrlpd"), "aqcoslgrmk", 0, 5, 0);
    test(S("ehmja"), "dabckmepqj", 0, 9, 1);
    test(S("mhqgd"), "pqscrjthli", 0, 10, 0);
    test(S("tgklq"), "kfphdcsjqmobliagtren", 0, 0, 0);
    test(S("bocjs"), "rokpefncljibsdhqtagm", 0, 1, 0);
    test(S("grbsd"), "afionmkphlebtcjqsgrd", 0, 10, 0);
    test(S("ofjqr"), "aenmqplidhkofrjbctsg", 0, 19, S::npos);
    test(S("btlfi"), "osjmbtcadhiklegrpqnf", 0, 20, S::npos);
    test(S("clrgb"), "", 1, 0, 1);
    test(S("tjmek"), "osmia", 1, 0, 1);
    test(S("bgstp"), "ckonl", 1, 1, 1);
    test(S("hstrk"), "ilcaj", 1, 2, 1);
    test(S("kmspj"), "lasiq", 1, 4, 1);
    test(S("tjboh"), "kfqmr", 1, 5, 1);
    test(S("ilbcj"), "klnitfaobg", 1, 0, 1);
    test(S("jkngf"), "gjhmdlqikp", 1, 1, 1);
    test(S("gfcql"), "skbgtahqej", 1, 5, 1);
    test(S("dqtlg"), "bjsdgtlpkf", 1, 9, 1);
    test(S("bthpg"), "bjgfmnlkio", 1, 10, 1);
    test(S("dgsnq"), "lbhepotfsjdqigcnamkr", 1, 0, 1);
    test(S("rmfhp"), "tebangckmpsrqdlfojhi", 1, 1, 1);
    test(S("jfdam"), "joflqbdkhtegimscpanr", 1, 10, 3);
    test(S("edapb"), "adpmcohetfbsrjinlqkg", 1, 19, S::npos);
    test(S("brfsm"), "iacldqjpfnogbsrhmetk", 1, 20, S::npos);
    test(S("ndrhl"), "", 2, 0, 2);
    test(S("mrecp"), "otkgb", 2, 0, 2);
    test(S("qlasf"), "cqsjl", 2, 1, 2);
    test(S("smaqd"), "dpifl", 2, 2, 2);
    test(S("hjeni"), "oapht", 2, 4, 2);
    test(S("ocmfj"), "cifts", 2, 5, 2);
    test(S("hmftq"), "nmsckbgalo", 2, 0, 2);
    test(S("fklad"), "tpksqhamle", 2, 1, 2);
    test(S("dirnm"), "tpdrchmkji", 2, 5, 3);
    test(S("hrgdc"), "ijagfkblst", 2, 9, 3);
    test(S("ifakg"), "kpocsignjb", 2, 10, 2);
    test(S("ebrgd"), "pecqtkjsnbdrialgmohf", 2, 0, 2);
    test(S("rcjml"), "aiortphfcmkjebgsndql", 2, 1, 2);
    test(S("peqmt"), "sdbkeamglhipojqftrcn", 2, 10, 2);
    test(S("frehn"), "ljqncehgmfktroapidbs", 2, 19, S::npos);
    test(S("tqolf"), "rtcfodilamkbenjghqps", 2, 20, S::npos);
    test(S("cjgao"), "", 4, 0, 4);
    test(S("kjplq"), "mabns", 4, 0, 4);
    test(S("herni"), "bdnrp", 4, 1, 4);
    test(S("tadrb"), "scidp", 4, 2, 4);
    test(S("pkfeo"), "agbjl", 4, 4, 4);
    test(S("hoser"), "jfmpr", 4, 5, S::npos);
    test(S("kgrsp"), "rbpefghsmj", 4, 0, 4);
    test(S("pgejb"), "apsfntdoqc", 4, 1, 4);
    test(S("thlnq"), "ndkjeisgcl", 4, 5, 4);
    test(S("nbmit"), "rnfpqatdeo", 4, 9, S::npos);
    test(S("jgmib"), "bntjlqrfik", 4, 10, S::npos);
    test(S("ncrfj"), "kcrtmpolnaqejghsfdbi", 4, 0, 4);
    test(S("ncsik"), "lobheanpkmqidsrtcfgj", 4, 1, 4);
    test(S("sgbfh"), "athdkljcnreqbgpmisof", 4, 10, S::npos);
    test(S("dktbn"), "qkdmjialrscpbhefgont", 4, 19, S::npos);
    test(S("fthqm"), "dmasojntqleribkgfchp", 4, 20, S::npos);
    test(S("klopi"), "", 5, 0, S::npos);
    test(S("dajhn"), "psthd", 5, 0, S::npos);
    test(S("jbgno"), "rpmjd", 5, 1, S::npos);
    test(S("hkjae"), "dfsmk", 5, 2, S::npos);
}

template <class S>
void test1()
{
    test(S("gbhqo"), "skqne", 5, 4, S::npos);
    test(S("ktdor"), "kipnf", 5, 5, S::npos);
    test(S("ldprn"), "hmrnqdgifl", 5, 0, S::npos);
    test(S("egmjk"), "fsmjcdairn", 5, 1, S::npos);
    test(S("armql"), "pcdgltbrfj", 5, 5, S::npos);
    test(S("cdhjo"), "aekfctpirg", 5, 9, S::npos);
    test(S("jcons"), "ledihrsgpf", 5, 10, S::npos);
    test(S("cbrkp"), "mqcklahsbtirgopefndj", 5, 0, S::npos);
    test(S("fhgna"), "kmlthaoqgecrnpdbjfis", 5, 1, S::npos);
    test(S("ejfcd"), "sfhbamcdptojlkrenqgi", 5, 10, S::npos);
    test(S("kqjhe"), "pbniofmcedrkhlstgaqj", 5, 19, S::npos);
    test(S("pbdjl"), "mongjratcskbhqiepfdl", 5, 20, S::npos);
    test(S("gajqn"), "", 6, 0, S::npos);
    test(S("stedk"), "hrnat", 6, 0, S::npos);
    test(S("tjkaf"), "gsqdt", 6, 1, S::npos);
    test(S("dthpe"), "bspkd", 6, 2, S::npos);
    test(S("klhde"), "ohcmb", 6, 4, S::npos);
    test(S("bhlki"), "heatr", 6, 5, S::npos);
    test(S("lqmoh"), "pmblckedfn", 6, 0, S::npos);
    test(S("mtqin"), "aceqmsrbik", 6, 1, S::npos);
    test(S("dpqbr"), "lmbtdehjrn", 6, 5, S::npos);
    test(S("kdhmo"), "teqmcrlgib", 6, 9, S::npos);
    test(S("jblqp"), "njolbmspac", 6, 10, S::npos);
    test(S("qmjgl"), "pofnhidklamecrbqjgst", 6, 0, S::npos);
    test(S("rothp"), "jbhckmtgrqnosafedpli", 6, 1, S::npos);
    test(S("ghknq"), "dobntpmqklicsahgjerf", 6, 10, S::npos);
    test(S("eopfi"), "tpdshainjkbfoemlrgcq", 6, 19, S::npos);
    test(S("dsnmg"), "oldpfgeakrnitscbjmqh", 6, 20, S::npos);
    test(S("jnkrfhotgl"), "", 0, 0, 0);
    test(S("dltjfngbko"), "rqegt", 0, 0, 0);
    test(S("bmjlpkiqde"), "dashm", 0, 1, 0);
    test(S("skrflobnqm"), "jqirk", 0, 2, 0);
    test(S("jkpldtshrm"), "rckeg", 0, 4, 0);
    test(S("ghasdbnjqo"), "jscie", 0, 5, 0);
    test(S("igrkhpbqjt"), "efsphndliq", 0, 0, 0);
    test(S("ikthdgcamf"), "gdicosleja", 0, 1, 0);
    test(S("pcofgeniam"), "qcpjibosfl", 0, 5, 2);
    test(S("rlfjgesqhc"), "lrhmefnjcq", 0, 9, 4);
    test(S("itphbqsker"), "dtablcrseo", 0, 10, 0);
    test(S("skjafcirqm"), "apckjsftedbhgomrnilq", 0, 0, 0);
    test(S("tcqomarsfd"), "pcbrgflehjtiadnsokqm", 0, 1, 0);
    test(S("rocfeldqpk"), "nsiadegjklhobrmtqcpf", 0, 10, 0);
    test(S("cfpegndlkt"), "cpmajdqnolikhgsbretf", 0, 19, 1);
    test(S("fqbtnkeasj"), "jcflkntmgiqrphdosaeb", 0, 20, S::npos);
    test(S("shbcqnmoar"), "", 1, 0, 1);
    test(S("bdoshlmfin"), "ontrs", 1, 0, 1);
    test(S("khfrebnsgq"), "pfkna", 1, 1, 1);
    test(S("getcrsaoji"), "ekosa", 1, 2, 2);
    test(S("fjiknedcpq"), "anqhk", 1, 4, 1);
    test(S("tkejgnafrm"), "jekca", 1, 5, 4);
    test(S("jnakolqrde"), "ikemsjgacf", 1, 0, 1);
    test(S("lcjptsmgbe"), "arolgsjkhm", 1, 1, 1);
    test(S("itfsmcjorl"), "oftkbldhre", 1, 5, 3);
    test(S("omchkfrjea"), "gbkqdoeftl", 1, 9, 1);
    test(S("cigfqkated"), "sqcflrgtim", 1, 10, 5);
    test(S("tscenjikml"), "fmhbkislrjdpanogqcet", 1, 0, 1);
    test(S("qcpaemsinf"), "rnioadktqlgpbcjsmhef", 1, 1, 1);
    test(S("gltkojeipd"), "oakgtnldpsefihqmjcbr", 1, 10, 5);
    test(S("qistfrgnmp"), "gbnaelosidmcjqktfhpr", 1, 19, 5);
    test(S("bdnpfcqaem"), "akbripjhlosndcmqgfet", 1, 20, S::npos);
    test(S("ectnhskflp"), "", 5, 0, 5);
    test(S("fgtianblpq"), "pijag", 5, 0, 5);
    test(S("mfeqklirnh"), "jrckd", 5, 1, 5);
    test(S("astedncjhk"), "qcloh", 5, 2, 5);
    test(S("fhlqgcajbr"), "thlmp", 5, 4, 5);
    test(S("epfhocmdng"), "qidmo", 5, 5, 5);
    test(S("apcnsibger"), "lnegpsjqrd", 5, 0, 5);
    test(S("aqkocrbign"), "rjqdablmfs", 5, 1, 6);
    test(S("ijsmdtqgce"), "enkgpbsjaq", 5, 5, 5);
    test(S("clobgsrken"), "kdsgoaijfh", 5, 9, 6);
    test(S("jbhcfposld"), "trfqgmckbe", 5, 10, 5);
    test(S("oqnpblhide"), "igetsracjfkdnpoblhqm", 5, 0, 5);
    test(S("lroeasctif"), "nqctfaogirshlekbdjpm", 5, 1, 5);
    test(S("bpjlgmiedh"), "csehfgomljdqinbartkp", 5, 10, 6);
    test(S("pamkeoidrj"), "qahoegcmplkfsjbdnitr", 5, 19, 8);
    test(S("espogqbthk"), "dpteiajrqmsognhlfbkc", 5, 20, S::npos);
    test(S("shoiedtcjb"), "", 9, 0, 9);
    test(S("ebcinjgads"), "tqbnh", 9, 0, 9);
    test(S("dqmregkcfl"), "akmle", 9, 1, 9);
    test(S("ngcrieqajf"), "iqfkm", 9, 2, 9);
    test(S("qosmilgnjb"), "tqjsr", 9, 4, 9);
    test(S("ikabsjtdfl"), "jplqg", 9, 5, S::npos);
    test(S("ersmicafdh"), "oilnrbcgtj", 9, 0, 9);
    test(S("fdnplotmgh"), "morkglpesn", 9, 1, 9);
    test(S("fdbicojerm"), "dmicerngat", 9, 5, S::npos);
    test(S("mbtafndjcq"), "radgeskbtc", 9, 9, 9);
    test(S("mlenkpfdtc"), "ljikprsmqo", 9, 10, 9);
    test(S("ahlcifdqgs"), "trqihkcgsjamfdbolnpe", 9, 0, 9);
    test(S("bgjemaltks"), "lqmthbsrekajgnofcipd", 9, 1, 9);
    test(S("pdhslbqrfc"), "jtalmedribkgqsopcnfh", 9, 10, 9);
    test(S("dirhtsnjkc"), "spqfoiclmtagejbndkrh", 9, 19, S::npos);
    test(S("dlroktbcja"), "nmotklspigjrdhcfaebq", 9, 20, S::npos);
    test(S("ncjpmaekbs"), "", 10, 0, S::npos);
    test(S("hlbosgmrak"), "hpmsd", 10, 0, S::npos);
    test(S("pqfhsgilen"), "qnpor", 10, 1, S::npos);
    test(S("gqtjsbdckh"), "otdma", 10, 2, S::npos);
    test(S("cfkqpjlegi"), "efhjg", 10, 4, S::npos);
    test(S("beanrfodgj"), "odpte", 10, 5, S::npos);
    test(S("adtkqpbjfi"), "bctdgfmolr", 10, 0, S::npos);
    test(S("iomkfthagj"), "oaklidrbqg", 10, 1, S::npos);
}

template <class S>
void test2()
{
    test(S("sdpcilonqj"), "dnjfsagktr", 10, 5, S::npos);
    test(S("gtfbdkqeml"), "nejaktmiqg", 10, 9, S::npos);
    test(S("bmeqgcdorj"), "pjqonlebsf", 10, 10, S::npos);
    test(S("etqlcanmob"), "dshmnbtolcjepgaikfqr", 10, 0, S::npos);
    test(S("roqmkbdtia"), "iogfhpabtjkqlrnemcds", 10, 1, S::npos);
    test(S("kadsithljf"), "ngridfabjsecpqltkmoh", 10, 10, S::npos);
    test(S("sgtkpbfdmh"), "athmknplcgofrqejsdib", 10, 19, S::npos);
    test(S("qgmetnabkl"), "ldobhmqcafnjtkeisgrp", 10, 20, S::npos);
    test(S("cqjohampgd"), "", 11, 0, S::npos);
    test(S("hobitmpsan"), "aocjb", 11, 0, S::npos);
    test(S("tjehkpsalm"), "jbrnk", 11, 1, S::npos);
    test(S("ngfbojitcl"), "tqedg", 11, 2, S::npos);
    test(S("rcfkdbhgjo"), "nqskp", 11, 4, S::npos);
    test(S("qghptonrea"), "eaqkl", 11, 5, S::npos);
    test(S("hnprfgqjdl"), "reaoicljqm", 11, 0, S::npos);
    test(S("hlmgabenti"), "lsftgajqpm", 11, 1, S::npos);
    test(S("ofcjanmrbs"), "rlpfogmits", 11, 5, S::npos);
    test(S("jqedtkornm"), "shkncmiaqj", 11, 9, S::npos);
    test(S("rfedlasjmg"), "fpnatrhqgs", 11, 10, S::npos);
    test(S("talpqjsgkm"), "sjclemqhnpdbgikarfot", 11, 0, S::npos);
    test(S("lrkcbtqpie"), "otcmedjikgsfnqbrhpla", 11, 1, S::npos);
    test(S("cipogdskjf"), "bonsaefdqiprkhlgtjcm", 11, 10, S::npos);
    test(S("nqedcojahi"), "egpscmahijlfnkrodqtb", 11, 19, S::npos);
    test(S("hefnrkmctj"), "kmqbfepjthgilscrndoa", 11, 20, S::npos);
    test(S("atqirnmekfjolhpdsgcb"), "", 0, 0, 0);
    test(S("echfkmlpribjnqsaogtd"), "prboq", 0, 0, 0);
    test(S("qnhiftdgcleajbpkrosm"), "fjcqh", 0, 1, 0);
    test(S("chamfknorbedjitgslpq"), "fmosa", 0, 2, 0);
    test(S("njhqpibfmtlkaecdrgso"), "qdbok", 0, 4, 0);
    test(S("ebnghfsqkprmdcljoiat"), "amslg", 0, 5, 0);
    test(S("letjomsgihfrpqbkancd"), "smpltjneqb", 0, 0, 0);
    test(S("nblgoipcrqeaktshjdmf"), "flitskrnge", 0, 1, 0);
    test(S("cehkbngtjoiflqapsmrd"), "pgqihmlbef", 0, 5, 0);
    test(S("mignapfoklbhcqjetdrs"), "cfpdqjtgsb", 0, 9, 0);
    test(S("ceatbhlsqjgpnokfrmdi"), "htpsiaflom", 0, 10, 0);
    test(S("ocihkjgrdelpfnmastqb"), "kpjfiaceghsrdtlbnomq", 0, 0, 0);
    test(S("noelgschdtbrjfmiqkap"), "qhtbomidljgafneksprc", 0, 1, 0);
    test(S("dkclqfombepritjnghas"), "nhtjobkcefldimpsaqgr", 0, 10, 0);
    test(S("miklnresdgbhqcojftap"), "prabcjfqnoeskilmtgdh", 0, 19, 11);
    test(S("htbcigojaqmdkfrnlsep"), "dtrgmchilkasqoebfpjn", 0, 20, S::npos);
    test(S("febhmqtjanokscdirpgl"), "", 1, 0, 1);
    test(S("loakbsqjpcrdhftniegm"), "sqome", 1, 0, 1);
    test(S("reagphsqflbitdcjmkno"), "smfte", 1, 1, 1);
    test(S("jitlfrqemsdhkopncabg"), "ciboh", 1, 2, 2);
    test(S("mhtaepscdnrjqgbkifol"), "haois", 1, 4, 2);
    test(S("tocesrfmnglpbjihqadk"), "abfki", 1, 5, 1);
    test(S("lpfmctjrhdagneskbqoi"), "frdkocntmq", 1, 0, 1);
    test(S("lsmqaepkdhncirbtjfgo"), "oasbpedlnr", 1, 1, 1);
    test(S("epoiqmtldrabnkjhcfsg"), "kltqmhgand", 1, 5, 1);
    test(S("emgasrilpknqojhtbdcf"), "gdtfjchpmr", 1, 9, 3);
    test(S("hnfiagdpcklrjetqbsom"), "ponmcqblet", 1, 10, 2);
    test(S("nsdfebgajhmtricpoklq"), "sgphqdnofeiklatbcmjr", 1, 0, 1);
    test(S("atjgfsdlpobmeiqhncrk"), "ljqprsmigtfoneadckbh", 1, 1, 1);
    test(S("sitodfgnrejlahcbmqkp"), "ligeojhafnkmrcsqtbdp", 1, 10, 2);
    test(S("fraghmbiceknltjpqosd"), "lsimqfnjarbopedkhcgt", 1, 19, 13);
    test(S("pmafenlhqtdbkirjsogc"), "abedmfjlghniorcqptks", 1, 20, S::npos);
    test(S("pihgmoeqtnakrjslcbfd"), "", 10, 0, 10);
    test(S("gjdkeprctqblnhiafsom"), "hqtoa", 10, 0, 10);
    test(S("mkpnblfdsahrcqijteog"), "cahif", 10, 1, 10);
    test(S("gckarqnelodfjhmbptis"), "kehis", 10, 2, 10);
    test(S("gqpskidtbclomahnrjfe"), "kdlmh", 10, 4, 11);
    test(S("pkldjsqrfgitbhmaecno"), "paeql", 10, 5, 10);
    test(S("aftsijrbeklnmcdqhgop"), "aghoqiefnb", 10, 0, 10);
    test(S("mtlgdrhafjkbiepqnsoc"), "jrbqaikpdo", 10, 1, 10);
    test(S("pqgirnaefthokdmbsclj"), "smjonaeqcl", 10, 5, 10);
    test(S("kpdbgjmtherlsfcqoina"), "eqbdrkcfah", 10, 9, 11);
    test(S("jrlbothiknqmdgcfasep"), "kapmsienhf", 10, 10, 10);
    test(S("mjogldqferckabinptsh"), "jpqotrlenfcsbhkaimdg", 10, 0, 10);
    test(S("apoklnefbhmgqcdrisjt"), "jlbmhnfgtcqprikeados", 10, 1, 10);
    test(S("ifeopcnrjbhkdgatmqls"), "stgbhfmdaljnpqoicker", 10, 10, 11);
    test(S("ckqhaiesmjdnrgolbtpf"), "oihcetflbjagdsrkmqpn", 10, 19, 11);
    test(S("bnlgapfimcoterskqdjh"), "adtclebmnpjsrqfkigoh", 10, 20, S::npos);
    test(S("kgdlrobpmjcthqsafeni"), "", 19, 0, 19);
    test(S("dfkechomjapgnslbtqir"), "beafg", 19, 0, 19);
    test(S("rloadknfbqtgmhcsipje"), "iclat", 19, 1, 19);
    test(S("mgjhkolrnadqbpetcifs"), "rkhnf", 19, 2, 19);
    test(S("cmlfakiojdrgtbsphqen"), "clshq", 19, 4, 19);
    test(S("kghbfipeomsntdalrqjc"), "dtcoj", 19, 5, S::npos);
    test(S("eldiqckrnmtasbghjfpo"), "rqosnjmfth", 19, 0, 19);
    test(S("abqjcfedgotihlnspkrm"), "siatdfqglh", 19, 1, 19);
    test(S("qfbadrtjsimkolcenhpg"), "mrlshtpgjq", 19, 5, 19);
    test(S("abseghclkjqifmtodrnp"), "adlcskgqjt", 19, 9, 19);
    test(S("ibmsnlrjefhtdokacqpg"), "drshcjknaf", 19, 10, 19);
    test(S("mrkfciqjebaponsthldg"), "etsaqroinghpkjdlfcbm", 19, 0, 19);
    test(S("mjkticdeoqshpalrfbgn"), "sgepdnkqliambtrocfhj", 19, 1, 19);
    test(S("rqnoclbdejgiphtfsakm"), "nlmcjaqgbsortfdihkpe", 19, 10, S::npos);
    test(S("plkqbhmtfaeodjcrsing"), "racfnpmosldibqkghjet", 19, 19, S::npos);
    test(S("oegalhmstjrfickpbndq"), "fjhdsctkqeiolagrnmbp", 19, 20, S::npos);
    test(S("rdtgjcaohpblniekmsfq"), "", 20, 0, S::npos);
    test(S("ofkqbnjetrmsaidphglc"), "ejanp", 20, 0, S::npos);
    test(S("grkpahljcftesdmonqib"), "odife", 20, 1, S::npos);
    test(S("jimlgbhfqkteospardcn"), "okaqd", 20, 2, S::npos);
    test(S("gftenihpmslrjkqadcob"), "lcdbi", 20, 4, S::npos);
    test(S("bmhldogtckrfsanijepq"), "fsqbj", 20, 5, S::npos);
    test(S("nfqkrpjdesabgtlcmoih"), "bigdomnplq", 20, 0, S::npos);
    test(S("focalnrpiqmdkstehbjg"), "apiblotgcd", 20, 1, S::npos);
    test(S("rhqdspkmebiflcotnjga"), "acfhdenops", 20, 5, S::npos);
    test(S("rahdtmsckfboqlpniegj"), "jopdeamcrk", 20, 9, S::npos);
    test(S("fbkeiopclstmdqranjhg"), "trqncbkgmh", 20, 10, S::npos);
    test(S("lifhpdgmbconstjeqark"), "tomglrkencbsfjqpihda", 20, 0, S::npos);
}

template <class S>
void test3()
{
    test(S("pboqganrhedjmltsicfk"), "gbkhdnpoietfcmrslajq", 20, 1, S::npos);
    test(S("klchabsimetjnqgorfpd"), "rtfnmbsglkjaichoqedp", 20, 10, S::npos);
    test(S("sirfgmjqhctndbklaepo"), "ohkmdpfqbsacrtjnlgei", 20, 19, S::npos);
    test(S("rlbdsiceaonqjtfpghkm"), "dlbrteoisgphmkncajfq", 20, 20, S::npos);
    test(S("ecgdanriptblhjfqskom"), "", 21, 0, S::npos);
    test(S("fdmiarlpgcskbhoteqjn"), "sjrlo", 21, 0, S::npos);
    test(S("rlbstjqopignecmfadkh"), "qjpor", 21, 1, S::npos);
    test(S("grjpqmbshektdolcafni"), "odhfn", 21, 2, S::npos);
    test(S("sakfcohtqnibprjmlged"), "qtfin", 21, 4, S::npos);
    test(S("mjtdglasihqpocebrfkn"), "hpqfo", 21, 5, S::npos);
    test(S("okaplfrntghqbmeicsdj"), "fabmertkos", 21, 0, S::npos);
    test(S("sahngemrtcjidqbklfpo"), "brqtgkmaej", 21, 1, S::npos);
    test(S("dlmsipcnekhbgoaftqjr"), "nfrdeihsgl", 21, 5, S::npos);
    test(S("ahegrmqnoiklpfsdbcjt"), "hlfrosekpi", 21, 9, S::npos);
    test(S("hdsjbnmlegtkqripacof"), "atgbkrjdsm", 21, 10, S::npos);
    test(S("pcnedrfjihqbalkgtoms"), "blnrptjgqmaifsdkhoec", 21, 0, S::npos);
    test(S("qjidealmtpskrbfhocng"), "ctpmdahebfqjgknloris", 21, 1, S::npos);
    test(S("qeindtagmokpfhsclrbj"), "apnkeqthrmlbfodiscgj", 21, 10, S::npos);
    test(S("kpfegbjhsrnodltqciam"), "jdgictpframeoqlsbknh", 21, 19, S::npos);
    test(S("hnbrcplsjfgiktoedmaq"), "qprlsfojamgndekthibc", 21, 20, S::npos);
}

int main(int, char**)
{
    {
    typedef std::string S;
    test0<S>();
    test1<S>();
    test2<S>();
    test3<S>();
    }
    {
    typedef std::basic_string<char, std::char_traits<char>, min_allocator<char>> S;
    test0<S>();
    test1<S>();
    test2<S>();
    test3<S>();
    }

  return 0;
}
