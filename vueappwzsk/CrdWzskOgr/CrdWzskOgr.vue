<template>
	<v-container v-if="initdone">
		<PnlWzskOgrList
			v-on:request="handleRequest"
			ref="PnlWzskOgrList"
			:scrJref=statshr.scrJrefList
		/>
		<PnlWzskOgrRec
			v-on:crdopen="handleCrdopen"
			v-on:request="handleRequest"
			ref="PnlWzskOgrRec"
			:scrJref=statshr.scrJrefRec
		/>
	</v-container>
</template>

<script>
	import Wzsk from '../../scripts/Wzsk';

	/*
	*/
	import PnlWzskOgrList from './PnlWzskOgrList';
	import PnlWzskOgrRec from './PnlWzskOgrRec';
	/*
	*/

	/*
	<!-- IP import.cust - INSERT -->
	*/

	export default {
		name: 'CrdWzskOgr',

		props: {
			scrJref: String
		},

		components: {
			/*
			*/
			PnlWzskOgrList,
			PnlWzskOgrRec
			/*
			*/
		},

		mounted() {
			//console.log("CrdWzskOgr.mounted() with scrJref = " + this.scrJref);

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

				if (dpcheng.ContInfWzskOgr) this.continf = dpcheng.ContInfWzskOgr;
				if (dpcheng.FeedFSge) this.feedFSge = dpcheng.FeedFSge;
				if (dpcheng.StatAppWzskOgr) this.statapp = dpcheng.StatAppWzskOgr;
				if (dpcheng.StatShrWzskOgr) {
					if (this.statshr != null) {
						dlgopen = (dpcheng.StatShrWzskOgr.scrJrefDlgnew != "");
						dlgclose = (this.statshr.scrJrefDlgnew != "");
						if (dlgopen && dlgclose) {
							dlgopen = false;
							dlgclose = false;
						}
						if (dlgopen) {
							if (dpcheng.StatShrWzskOgr.scrJrefDlgnew != "") {
								srefDlg = "DlgWzskOgrNew";
								scrJrefDlg = dpcheng.StatShrWzskOgr.scrJrefDlgnew;
							}
						}
					}
					this.statshr = dpcheng.StatShrWzskOgr;
				}
				if (dpcheng.TagWzskOgr) {
					Wzsk.unescapeBlock(dpcheng.TagWzskOgr);
					this.tag = dpcheng.TagWzskOgr;
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
					if (obj.scrJref == this.statshr.scrJrefList) this.$refs.PnlWzskOgrList.handleReply(obj);
					else this.$refs.PnlWzskOgrRec.handleReply(obj);
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
					if (obj.srefIxWzskVDpch == "DpchEngWzskOgrData") this.mergeDpchEngData(obj.dpcheng);
					processed = true;

				} else if (this.initdone) {
					/*
					*/
					if (obj.dpcheng.scrJref == this.statshr.scrJrefList) {
						this.$refs.PnlWzskOgrList.handleUpdate(obj);
						processed = true;
					} else processed = this.$refs.PnlWzskOgrRec.handleUpdate(obj);
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
