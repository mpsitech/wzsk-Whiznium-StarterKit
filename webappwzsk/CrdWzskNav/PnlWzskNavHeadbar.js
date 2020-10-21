/**
  * \file PnlWzskNavHeadbar.js
  * web client functionality for panel PnlWzskNavHeadbar
  * \author Catherine Johnson
  * \date created: 18 Oct 2020
  * \date modified: 18 Oct 2020
  */

// --- view initialization
function getMenAvail(short) {
	return(retrieveSi(srcdoc, "StatShrWzskNavHeadbar", "Men" + short + "Avail") == "true");
};

function getMenCptwidth(short) {
	return(parseInt(retrieveSi(srcdoc, "StgInfWzskNavHeadbar", "Men" + short + "Cptwidth")));
};

function getMenLeft(short) {
	var left = 3;

	if (short == "App") return(left);
	left += getMenCptwidth("App") + 1;

	if (short == "Ses") return(left);
	left += getMenCptwidth("Ses") + 1;

	if (short == "Crd") return(left);
	if (getMenAvail("Crd")) left += getMenCptwidth("Crd") + 1;

	return left;
};

function init() {
	contdoc = doc.getElementById("Headbar_cont").contentDocument;

	var w, wFill;
	wFill = 995;

	w = getMenCptwidth("App"); contdoc.getElementById("colMenApp").setAttribute("width", "" + w); wFill -= w + 1;
	setTextContent(contdoc, contdoc.getElementById("MenApp"), "\\u00a0" + retrieveTi(srcdoc, "TagWzskNavHeadbar", "MenApp") + "\\u00a0");
	w = getMenCptwidth("Ses"); contdoc.getElementById("colMenSes").setAttribute("width", "" + w); wFill -= w + 1;
	setTextContent(contdoc, contdoc.getElementById("MenSes"), "\\u00a0" + retrieveTi(srcdoc, "TagWzskNavHeadbar", "MenSes") + "\\u00a0");
	w = getMenCptwidth("Crd"); contdoc.getElementById("colMenCrd").setAttribute("width", "" + w); wFill -= w + 1;
	setTextContent(contdoc, contdoc.getElementById("MenCrd"), "\\u00a0" + retrieveTi(srcdoc, "TagWzskNavHeadbar", "MenCrd") + "\\u00a0");
	if (!getMenAvail("Crd")) contdoc.getElementById("tdMenCrd").setAttribute("class", "hide");

	contdoc.getElementById("colFill").setAttribute("width", "" + wFill);
};

// --- event handlers
function handleLoad() {
	scrJref = location.search.substr(location.search.indexOf("scrJref=")+8);

	doc = document;
	srcdoc = doc.getElementById("Headbar_src").contentDocument;

	var str = serializeDpchApp("DpchAppWzskInit", scrJref);
	sendReq(str, doc, handleDpchAppInitReply, true);
};

function handleMenAppClick() {
	getCrdwnd().toggleMenu("App", getMenLeft("App"), parseInt(retrieveSi(srcdoc, "StgInfWzskNavHeadbar", "MenAppWidth")), 63);
};

function handleMenSesClick() {
	getCrdwnd().toggleMenu("Ses", getMenLeft("Ses"), parseInt(retrieveSi(srcdoc, "StgInfWzskNavHeadbar", "MenSesWidth")), 103);
};

function handleMenCrdClick() {
	getCrdwnd().toggleMenu("Crd", getMenLeft("Crd"), parseInt(retrieveSi(srcdoc, "StgInfWzskNavHeadbar", "MenCrdWidth")), 224);
};

// --- server interaction
function mergeDpchEngData(dom) {
	var mask = [];

	if (updateSrcblock(dom, "DpchEngWzskNavHeadbarData", "StatShrWzskNavHeadbar", srcdoc)) mask.push("statshr");
	if (updateSrcblock(dom, "DpchEngWzskNavHeadbarData", "StgInfWzskNavHeadbar", srcdoc)) mask.push("stginf");
	if (updateSrcblock(dom, "DpchEngWzskNavHeadbarData", "TagWzskNavHeadbar", srcdoc)) mask.push("tag");

	return mask;
};

function handleDpchAppInitReply() {
	var dom, blk;

	if (doc.req.readyState == 4) {
		dom = doc.req.responseXML;

		blk = retrieveBlock(dom, "//wzsk:*");
		if (blk) {
			if (blk.nodeName == "DpchEngWzskNavHeadbarData") {
				mergeDpchEngData(dom);
				init();

				getCrdwnd().setInitdone("Headbar");
			};
		};
	};
};

