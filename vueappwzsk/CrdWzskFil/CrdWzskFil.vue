<template>
	<v-container v-if="initdone">
		<PnlWzskFilList
			v-on:request="handleRequest"
			ref="PnlWzskFilList"
			:scrJref=statshr.scrJrefList
		/>
		<PnlWzskFilRec
			v-on:crdopen="handleCrdopen"
			v-on:request="handleRequest"
			ref="PnlWzskFilRec"
			:scrJref=statshr.scrJrefRec
		/>
	</v-container>
</template>

<script>
	import Wzsk from '../../scripts/Wzsk';

	/*
	*/
	import PnlWzskFilList from './PnlWzskFilList';
	import PnlWzskFilRec from './PnlWzskFilRec';
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'CrdWzskFil',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlWzskFilList,
			PnlWzskFilRec
			/*
			*/
		},

		mounted() {
			//console.log("CrdWzskFil.mounted() with scrJref = " + this.scrJref);

			const dpchapp = {
				"DpchAppWzskInit": {
					"scrJref": this.scrJref
				}
			};

			this.$emit("request", {scrJref: this.scrJref, dpchapp: dpchapp, then: "handleDpchAppInitReply"});
		},

		methods: {
			/*
			<!-- IP cust - INSERT -->
			*/

			mergeDpchEngData: function(dpcheng) {
				/*
				*/
				var dlgopen = false;
				var dlgclose = false;

				var srefDlg = "";
				var scrJrefDlg = "";

				if (dpcheng.ContInfWzskFil) this.continf = dpcheng.ContInfWzskFil;
				if (dpcheng.FeedFSge) this.feedFSge = dpcheng.FeedFSge;
				if (dpcheng.StatAppWzskFil) this.statapp = dpcheng.StatAppWzskFil;
				if (dpcheng.StatShrWzskFil) {
					if (this.statshr != null) {
						dlgopen = (dpcheng.StatShrWzskFil.scrJrefDlgdownload != "");
						dlgclose = (this.statshr.scrJrefDlgdownload != "");
						if (dlgopen && dlgclose) {
							dlgopen = false;
							dlgclose = false;
						}
						if (dlgopen) {
							if (dpcheng.StatShrWzskFil.scrJrefDlgdownload != "") {
								srefDlg = "DlgWzskFilDownload";
								scrJrefDlg = dpcheng.StatShrWzskFil.scrJrefDlgdownload;
							}
						}
					}
					this.statshr = dpcheng.StatShrWzskFil;
				}
				if (dpcheng.TagWzskFil) {
					Wzsk.unescapeBlock(dpcheng.TagWzskFil);
					this.tag = dpcheng.TagWzskFil;
				}

				if (dlgopen) this.$emit("dlgopen", {srefDlg: srefDlg, scrJrefDlg: scrJrefDlg});
				else if (dlgclose) this.$emit("dlgclose");
				/*
				*/
			},

			handleCrdopen: function(obj) {
				this.$emit("crdopen", obj)
			},

			handleRequest: function(obj) {
				this.$emit("request", obj)
			},

			handleReply: function(obj) {
				if (obj.scrJref == this.scrJref) {
					if (obj.then == "handleDpchAppInitReply") this.handleDpchAppInitReply(obj.dpcheng);

				} else if (this.initdone) {
					/*
					*/
					if (obj.scrJref == this.statshr.scrJrefList) this.$refs.PnlWzskFilList.handleReply(obj);
					else this.$refs.PnlWzskFilRec.handleReply(obj);
					/*
					*/
				}
			},

			handleDpchAppInitReply: function(dpcheng) {
				this.mergeDpchEngData(dpcheng);

				this.initdone = true;
			},

			handleUpdate: function(obj) {
				var processed = false;

				if (obj.dpcheng.scrJref == this.scrJref) {
					if (obj.srefIxWzskVDpch == "DpchEngWzskFilData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					/*
					*/
					if (obj.dpcheng.scrJref == this.statshr.scrJrefList) {
						this.$refs.PnlWzskFilList.handleUpdate(obj);
						processed = true;
					} else processed = this.$refs.PnlWzskFilRec.handleUpdate(obj);
					/*
					*/
				}

				//if (!processed) console.log("got a '" + obj.srefIxWzskVDpch + "' from job with scrJref " + obj.dpcheng.scrJref);

				return processed
			},
		},

		data: () => ({
			initdone: false,

			/*
			*/
			continf: null,

			feedFSge: null,

			statapp: null,

			statshr: null,

			tag: null,
			/*
			*/
			
			/*
			<!-- IP data.cust - INSERT -->
			*/
		})
	}
</script>
